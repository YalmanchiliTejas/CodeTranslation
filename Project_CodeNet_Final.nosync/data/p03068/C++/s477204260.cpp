#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void){
    int n,k;
    string s;
    cin >>n >>s >>k;

    for(int i = 0; i < s.size(); i++){
        if(s[i] != s[k-1]){
        printf("*");
        }else{
            printf("%c", s[k-1]);
        }
    }
    printf("\n");

    return 0;
}