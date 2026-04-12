#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <vector>
#include <cmath>

int main(void){
    int n;
    std::cin >> n;
    char s[n];
    std::cin >> s;
    int k;
    std::cin >> k;


    for(int i = 0; i < n; i++){
        if(s[k-1] == s[i]) continue;
        s[i] = '*';
    }

    std::cout << s;
    return 0;
}
