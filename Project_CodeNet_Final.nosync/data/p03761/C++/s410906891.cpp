#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define all(v) v.begin(), v.end()
#define ll long long
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<long long>;
using vvll = vector<vll>;

//snippets:tmp,cl,cvl,cs,co,coy,con,cov

int main(){
    ll n;
    cin >> n;
    vll d(26,1e9);
    rep(i,n){
        string s;
        cin>>s;
        vll d2(26,0);
        rep(j,s.size()){
            d2[s[j]-'a']++;
        }
        rep(j,26){
            d[j]=min(d[j],d2[j]);
        }
    }
    rep(i,26){
        rep(j,d[i]){
            cout << (char)(i+'a');
        }
    }
    cout<<endl;
}