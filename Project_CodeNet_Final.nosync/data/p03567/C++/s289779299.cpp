#include<bits/stdc++.h>

int main(void)
{
        char s[10] = {0};
        std::cin >> s;
        for(int i = 0; s[i]; i++){
                if(s[i] == 'A' && s[i+1] == 'C'){
                        std::cout << "Yes" << std::endl;
                        return 0;
                }
        }
        std::cout << "No" << std::endl;
        return 0;
}