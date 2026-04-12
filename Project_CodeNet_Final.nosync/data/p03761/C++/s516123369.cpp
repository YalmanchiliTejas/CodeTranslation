#include <bits/stdc++.h>
#define rep(i,a) for(int i=0;i<int(a);++i)
#define REP(i,a,b) for(int i=int(a);i<int(b);++i)
#define pb push_back
#define mp make_pair
#define F first
#define S second
using ll = long long;
using itn = int;
using namespace std;
static const long double GRATIO=(long double)(1+sqrt(5))/2;
ll GCD(ll a, ll b){
    return b ? GCD(b, a%b) : a;
}
ll LCM(ll a, ll b){
    return a/GCD(a,b)*b;
}
int main(){
    int n;
    cin>>n;
    vector<string> S(n);
    vector<int> alpha(26,1e9);
    rep(i,n) cin>>S.at(i);
    string s;
    rep(i,n){
        vector<int> tmp_alpha(26,0);
        rep(j,S.at(i).size()){
            tmp_alpha.at(S.at(i).at(j)-'a')++;
        }
        rep(j,26){
            alpha.at(j) = min(alpha.at(j),tmp_alpha.at(j));
        }
    }
    rep(i,26){
        rep(j,alpha.at(i)){
            cout<<(char)('a'+i);
        }
    }
    cout<<endl;
}
