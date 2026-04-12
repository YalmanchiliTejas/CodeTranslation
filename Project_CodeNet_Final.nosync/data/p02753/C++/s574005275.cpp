#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string S;
    cin >> S;
    bool ans = false;
    rep(i,2){
        if(S[i]!=S[i+1]){
            ans = true;
        }
    }
    if(ans)cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}