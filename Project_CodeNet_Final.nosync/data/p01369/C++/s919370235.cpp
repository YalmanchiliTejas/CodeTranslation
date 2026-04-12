#include <bits/stdc++.h>
using namespace std;

char hand[32] = "00000001111111110000100010";

int main(){
    string typ;
    while(cin >> typ){
        if(typ == "#") break;
        int ch = 0;
        for(int i = 1; i < typ.size(); i++){
            ch += abs(hand[typ[i] - 97] - hand[typ[i-1] - 97]);
        }
        printf("%d\n", ch);
    }    
    return 0;
}