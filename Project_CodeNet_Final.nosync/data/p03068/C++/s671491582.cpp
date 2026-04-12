#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define agewari(a, b) ((ll)a + ((ll)b - 1)) / b
const int MOD = 1000000007;
const long long INF = 1LL << 60;
using Graph = vector<vector<ll>>;

int main()
{
    ll n,k;
    string s;
    cin>>n>>s>>k;
    k--;
    char tmp=s[k];
    rep(i,n){
        if(s[i]!=tmp)s[i]='*';
    }
    cout<<s<<endl;
}