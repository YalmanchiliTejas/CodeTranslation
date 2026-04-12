#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <array>
#include <math.h>
#include <sstream>
typedef long long ll;
using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    std::cin >> s;
    for (int i = 0; i < s.length()-1; i++) {
        if (s[i] == 'A' && s[i+1] == 'C') {
            std::cout << "Yes" << std::endl;
            return 0;
        }
    }
    std::cout << "No" << std::endl;
    return 0;
}