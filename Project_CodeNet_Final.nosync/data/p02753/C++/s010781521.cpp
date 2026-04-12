#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

int main(){
    string S;
    cin >> S;
    char s = S[0];
    for(int i = 1; i < 3; i++){
        if(S[i] != s){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}