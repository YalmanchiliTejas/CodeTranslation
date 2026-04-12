#include <iostream>
#include <string>
#include <vector>

using StateVec = std::vector<bool>;

bool findSolution(const StateVec& ls, StateVec& solution) {
    if (ls.size() < 3) {
        return false;
    }

    const auto lastI = ls.size() - 1u;
    const bool initSet[][2] = {{true, true}, {true, false}, {false, true}, {false, false}};

    for(const auto& s : initSet) {
        solution[0] = s[0];
        solution[1] = s[1];
        for(decltype(ls.size()) i = 1; i < lastI; ++i) {
            solution[i+1] = solution[i] ^ ls[i] ^ solution[i-1];
        }

        if (!(solution[lastI] ^ ls[lastI] ^ solution[lastI-1] ^ solution[0]) &&
            !(solution[0] ^ ls[0] ^ solution[lastI] ^ solution[1])) {
            return true;
        }
    }

    return false;
}

int main(int argc, char* argv[]) {
    std::string line;
    std::getline(std::cin, line);
    std::getline(std::cin, line);

    StateVec ls;
    for(auto c : line) {
        ls.push_back(c == 'o');
    }

    StateVec solution;
    solution.assign(ls.size(), false);

    std::string str;
    if (findSolution(ls, solution)) {
        for(auto b : solution) {
            str += (b) ? "S" : "W";
        }
    } else {
        str += "-1";
    }

    std::cout << str << "\n";
    return 0;
}
