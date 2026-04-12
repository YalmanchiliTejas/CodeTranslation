#include <iostream>
#include <vector>
#include <string>

//using namespace std;

int main()
{
    uint32_t nn;
    std::string s;
    

    for(int i = 0; i < 3; i++){
        std::cin >> s[i];
    }

    if(s[0] == s[1] && s[1] == s[2] && s[2] == s[0]){
        std::cout << "No" << std::endl;
        return 0;
    }
    std::cout << "Yes" << std::endl;

    return 0;
}