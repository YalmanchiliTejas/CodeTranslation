#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
const int mod =1e+9+7;

int main(){
    ll n; cin>>n;
    vector<vector<ll>>a(n,vector<ll>(26));
    vector<string>s(n);
    rep(i,n){
        cin>>s[i];
        rep(j,s[i].size()){
            int x='z'-s[i][j];
            x=26-x;
            x--;
            a[i][x]++;
        }
    }
    char c='`';
    rep(i,26){
        ll mn=1000;
        c++;
        rep(j,n){
            mn=min(mn,a[j][i]);
        }
        rep(k,mn)cout<<c;
    }
    cout<<endl;

}






































