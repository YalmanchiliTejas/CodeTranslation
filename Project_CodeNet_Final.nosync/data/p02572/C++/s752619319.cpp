#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pii;
typedef long long ll;
const long long MOD=1000000007;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rep2(i,m,n) for(ll i=(m);i<(n);i++)
#define ALL(v) v.begin(), v.end()
#define pb push_back





int main(){


    ll n;
    cin>>n;

    vector<ll> data(n);
    rep(i,n){
        ll tmp;
        cin>>tmp;
        data.at(i)=tmp;
    }

    ll answer=0;

    ll tmp=0;

    rep(i,n){
        tmp+=data.at(i);
        tmp%=MOD;
    }

    ll tmp2=0;

    rep(i,n){
        ll nijo=(data.at(i)*data.at(i))%MOD;
        tmp2+=nijo;
        tmp2%=MOD;
    }

    answer=((tmp*tmp)%MOD)-tmp2;

    if (answer<0){
        answer+=MOD;
    }

    if (answer%2==1){
        answer+=MOD;
    }

    cout<<(answer/2)%MOD<<endl;

    






}