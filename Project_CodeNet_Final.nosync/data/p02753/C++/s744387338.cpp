#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <numeric>
#include <cstdlib>
#include <map>
#include <algorithm>

using namespace std;

int main(){
    string S;

    cin >> S;

    bool flag = false;

    for(int i = 0; i < 2; i++){
        if(S[i] != S[i+1]){
            flag = true;
            break; 
        }
    }

    if(flag){
        cout << "Yes" << endl;
    }else{
        cout <<  "No" << endl;
    }

    return 0;
}