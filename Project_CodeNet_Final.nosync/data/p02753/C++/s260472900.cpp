#include<bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define repk(i,k,n) for (ll i = k; i < (ll)(n); ++i)
#define MAX 500000001000000000
#define MOD 1000000007
typedef long long  ll;

using namespace std;



int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    if(s[0] == s[1] && s[1] == s[2]){
        cout << "No" << endl;
        return 0;
    }
    else{
        cout << "Yes" << endl;
        return 0;
    }

    return 0;
}
