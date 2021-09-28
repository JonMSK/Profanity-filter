#include <iostream>
#include <string>
#include <vector>
#include <sstream>

// Add words you want to filter here. 
// I'm sure the internet has a full list of swear words you could copy here if you want.
std::string profaneWords[]{
    "fuck",
    "shit",
    "yourmum",
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

int main() {
    std::cout << "Enter your sentence: ";

    // Init the inputString and get it into a string stream.
    std::string inputString{};
    std::getline(std::cin, inputString);
    std::istringstream stringStream{ inputString };

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

    std::cout << "------------------" << std::endl;;
    std::cout << "Filtered word: ";

    // Print filtered sentence.
    for (int i{ 0 }; i < individualWords.size(); ++i) {
        std::cout << individualWords[i] << ' ';
    }
    
    std::cout << std::endl;

	return 0;
}
