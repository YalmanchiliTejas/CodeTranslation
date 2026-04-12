#include <bits/stdc++.h>
using namespace std;


int main(){
    string S; cin >> S;
    int countA = 0, countB = 0;
    for(int i = 0; i < S.size(); i++){
        if(S.at(i) == 'A') countA++;
        if(S.at(i) == 'B') countB++;
    }
    if(countA == 2 || countB == 2) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}

