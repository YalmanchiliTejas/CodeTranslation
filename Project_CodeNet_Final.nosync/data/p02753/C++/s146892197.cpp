#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)

typedef long long ll;
using namespace std;
int mod = 1000000007;

int main(void){
    string S; cin >> S;
    if(S[0] == S[1] && S[1] == S[2]) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}