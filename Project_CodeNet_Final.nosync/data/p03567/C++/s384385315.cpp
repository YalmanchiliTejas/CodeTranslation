#include<bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;
    int cnt = 0;
    for(int i = 0; i < S.size()-1; i++) {
        if(S[i] == 'A' && S[i+1] == 'C') {
            cnt++;
        }
    }
    if(cnt > 0) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
