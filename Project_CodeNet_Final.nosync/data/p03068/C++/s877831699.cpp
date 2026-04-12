#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n,k;
    string s;
    cin >> n >> s >> k;
    char cr=s[k-1];
    for(ll i=0;i<n;i++){
        if(s[i]==cr) continue;
        s[i]='*';
    }
    cout << s << endl;
}