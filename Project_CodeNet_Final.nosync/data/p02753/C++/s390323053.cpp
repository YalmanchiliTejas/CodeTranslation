#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <stdio.h>
#include <cmath>
#include <queue>
typedef long long ll;
using namespace std;

int main(void){
    string S;
    cin >> S;
    for(int i = 1; i<S.length();i++){
        if(S[i]!=S[i-1]) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}

