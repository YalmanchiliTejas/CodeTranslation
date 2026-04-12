#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const  ll INF = 1e18;
const  ll MOD = 1e9 + 7;
#define all(v) v.begin(), v.end()
#define repi(i,n,init) for(ll i=init;i<(n);i++)
#define repd(i,n,init) for(ll i=(n);i>=init;i--)
#define repm(i,m) for(auto i=m.begin();i!=m.end();i++)

int main()
{
    string S;
    cin >> S;
    repi(i,S.length()-1,0){
        if(S.at(i) == 'A' && S.at(i+1) == 'C'){
            puts("Yes");
            return 0;
        }
    }
    puts("No");
    return 0;
}