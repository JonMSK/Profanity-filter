#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#ifndef GH_PROFANITY
#define GH_PROFANITY

std::string profaneWords[]{
    "fuck",
    "shit",
};

std::string calculateProfaneCover(std::string toProfane, char profaneCharacter = '*') {
    std::string returnCover{};

    for (int i{ 0 }; i < toProfane.size(); ++i) {
        returnCover.push_back(profaneCharacter);
    }

    return returnCover;
}

std::string lowerCaseConverter(std::string str) {
    std::string returnLower{};

    for (int i{ 0 }; i < str.size(); ++i) {
        returnLower.push_back(std::tolower(str[i]));
    }

    return returnLower;
}

std::string profanityFilter(std::string toProfane) {
    std::istringstream stringStream{ toProfane };

    // Init the vector which the split words will be added.
    std::vector<std::string> individualWords{};

    // Split the words and put them into the above vector.
    for (std::string tempString; stringStream >> tempString;) {
        individualWords.push_back(tempString);
    }

    // Profanity filter.
    for (int i{ 0 }; i < individualWords.size(); ++i) {
        std::string currentWord = individualWords[i];
        for (int a{ 0 }; a < std::size(profaneWords); ++a) {
            if (lowerCaseConverter(currentWord) == profaneWords[a]) {
                individualWords[i] = calculateProfaneCover(individualWords[i], '#');
            }
        }
    }

    std::string returnString{};

    for (int i{ 0 }; i < individualWords.size(); ++i) {
        returnString += individualWords[i];
        returnString += " ";
    }

    return returnString;
}

#endif