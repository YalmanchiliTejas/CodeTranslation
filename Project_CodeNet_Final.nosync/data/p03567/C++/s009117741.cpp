#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

int main(void){
    char S[6];
    cin >> S;
    
    int len = 0;
    while(S[len])
        len++;
    
    int k = 0;
    
    for(int i = 0; i < (len - 1); i++){
        if(S[i] == 'A' && S[i + 1] == 'C'){
            k = 1;
            break;
        }
    }
    
    if(k == 1){
        cout << "Yes" << endl;
    }
    
    else{
        cout << "No" << endl;
    }
    
    return 0;
        }
