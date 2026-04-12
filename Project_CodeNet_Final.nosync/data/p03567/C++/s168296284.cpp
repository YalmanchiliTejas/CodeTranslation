#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(void){
    string S;

    cin >> S;

    for(int i=0;i<S.size()-1;i++){
        if(S[i] == 'A' and S[i+1] == 'C'){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}