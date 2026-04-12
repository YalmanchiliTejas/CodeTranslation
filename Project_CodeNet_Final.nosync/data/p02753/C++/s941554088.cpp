#include<cstdio>
#include<iostream>
#include<cstring>

int main() {
    bool A = false,B = false;
    for(int i = 1;i <= 3;i++) {
        char ch; std::cin >> ch;
        if(ch == 'A') A = true;
        else B = true;
    }
    if(A && B) std::puts("Yes");
    else std::puts("No");
    return 0;
}