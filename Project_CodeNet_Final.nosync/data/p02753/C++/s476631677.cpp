#include <bits/stdc++.h>
#define int long long
using namespace std;
int MOD = 1000000007;

signed main(){
    string S;
    cin >> S;
    
    if(S[0] == S[1] && S[1] == S[2]) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}

