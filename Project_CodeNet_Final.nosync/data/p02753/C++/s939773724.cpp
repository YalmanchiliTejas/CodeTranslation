#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef vector<int> VI;
typedef vector<ll> VLL;
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int main(){
    string s,ans;
    cin >> s;

    if(s[0] != s[1] || s[1] != s[2]){
        ans = "Yes";
    }else ans = "No";

    cout << ans << endl;
}