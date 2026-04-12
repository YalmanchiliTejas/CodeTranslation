#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

#define ll long long

int main()
{
    std::string S;
    std::cin >> S;

    bool A = false;
    bool B = false;

    for(int i=0; i < 3; i++) {
        if(S[i] == 'A') A = true;
        if(S[i] == 'B') B = true;
    }

    if(A == true and B == true) std::cout << "Yes" << std::endl;
    else std::cout << "No" << std::endl;
}