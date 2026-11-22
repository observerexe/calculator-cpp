#include <iostream>
#include <string>
#include <vector>

struct Token {
    char op;
    double value;
};

std::vector<Token> tokenize(const std::string &input) {

    std::vector<Token> tokens;
    std::string stringValue;

    for (size_t i = 0; i <= input.size(); i++) {
        if (std::isdigit(input[i]) || input[i] == '.') {
            stringValue.push_back(input[i]);
            continue;
        } else if (!stringValue.empty()) {
            Token token{};
            token.value = std::stod(stringValue);
            tokens.push_back(token);
            stringValue.clear();
        }
        if (i < input.size()) {
            Token token{};
            token.op = input[i];
            tokens.push_back(token);
        }
    }
    return tokens;
}

int main() {

    std::string input;
    std::cin >> input;

    std::vector tokens = tokenize(input);

    for (size_t i = 0; i < tokens.size(); i++) {
        if (tokens[i].op != 0) {
            std::cout << tokens[i].op;
        } else {
            std::cout << tokens[i].value;
        }
        std::cout << " ";
    }
    return 0;
}
