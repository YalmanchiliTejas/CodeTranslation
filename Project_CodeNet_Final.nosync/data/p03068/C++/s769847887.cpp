#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod = int(1e9)+7;
using V = vector<ll>;
using P = pair<ll,ll>;

int main()
{
    int n;cin >>n;
    string s;cin >>s;
    int k;cin >> k;
    k--;
    char t=s[k];
    rep(i,n){
        if(s[i]==t)cout <<t;
        else cout << "*" ;
    }
    cout << endl;
    return 0;
}
