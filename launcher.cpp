#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

void boot();

void launcher() {
    std::string input;

    while (true) {
        std::cout << "OSIT_v0.1> ";
        std::getline(std::cin, input);

        std::stringstream ss(input);
        std::string cmd;
        double a, b;

        ss >> cmd;

        if (cmd == "help") {
            std::cout << "+----------------------+\n";
            std::cout << "|exit  - exit the os   |\n";
            std::cout << "|cls   - clear screen  |\n";
            std::cout << "|help  - show commands |\n";
            std::cout << "|add <a> <b>   - a + b |\n";
            std::cout << "|sub <a> <b>   - a - b |\n";
            std::cout << "|mul <a> <b>   - a * b |\n";
            std::cout << "|div <a> <b>   - a / b |\n";
            std::cout << "|pow <a> <b>   - a ^ b |\n";
            std::cout << "+----------------------+\n";
        }
        else if (cmd == "cls") {
            system("cls");
        }
        else if (cmd == "exit") {
            break;
        }
        else if (cmd == "add" || cmd == "sub" || cmd == "mul" || cmd == "div" || cmd == "pow") {
            if (!(ss >> a >> b)) {
                std::cout << "Usage: " << cmd << " a b\n";
                continue;
            }

            if (cmd == "add") {
                std::cout << a + b << "\n";
            }
            else if (cmd == "sub") {
                std::cout << a - b << "\n";
            }
            else if (cmd == "mul") {
                std::cout << a * b << "\n";
            }
            else if (cmd == "pow") {
                std::cout << pow(a, b) << "\n";
            }
            else if (cmd == "div") {
                if (b == 0) {
                    std::cout << "\033[31mError: division by zero\033[0m\n";
                } else {
                    std::cout << a / b << "\n";
                }
            }
        }
        else {
            std::cout << "\033[31mError: command not found\033[0m\n";
        }
    }
}

int main() {
    boot();
    launcher();
    return 0;
}