#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

#define mod 1000000007
#define all(x) (x).begin(), (x).end()
#define pb push_back

const long double PI = acos(-1);
 
ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a / gcd(a,b) * b;}
ll GetDigit(ll num) {return log10(num)+1;}

int main(){
    ll n;
    cin >> n;
    vector<string> s(n);
    for(ll i = 0; i < n; i++) cin >> s[i];

    ll abc[n][27];
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < 26; j++){
            char c = 'a' + j;
            abc[i][j] = count(all(s[i]), c);
        }
    }

    string ans = "";
    for(ll i = 0; i < 26; i++){
        ll cnt = 1000000;
        for(ll j = 0; j < n; j++){
            cnt = min(cnt, abc[j][i]);
        }
        for(ll j = 0; j < cnt; j++){
            ans += (char)('a' + i);
        }
    }

    cout << ans << endl;
    return 0;
}