#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i,n,m) for(int i=(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define REPR(i,n) for(int i=(n);i>=0;i--)
#define all(vec) vec.begin(),vec.end()
using vi=vector<int>;
using vvi=vector<vi>;
using vl=vector<ll>;
using vvl=vector<vl>;
using P=pair<ll,ll>;
using PP=pair<ll,P>;
using vp=vector<P>;
using vpp=vector<PP>;
using vs=vector<string>;
#define fi first
#define se second
#define pb push_back
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}
template<class T>bool chmin(T &a,const T &b){if(a>b){a=b;return true;}return false;}
const ll MOD=1000000007LL;
const int INF=1<<30;
const ll LINF=1LL<<60;
vector<string> zip(vector<string> vec){
    vector<string> res;
    REP(i,vec.size()){
        if(vec[i]!=string(vec[0].size(),'.')){
            res.push_back(vec[i]);
        }
    }
    return res;
}
vector<string> rotate(vector<string> vec){
    vector<string> res(vec[0].size());
    REP(i,vec.size()){
        REP(j,vec[0].size()){
            res[j]+=vec[i][j];
        }
    }
    return res;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<string> vec(n);
    REP(i,n){
        cin>>vec[i];
    }
    vec=zip(vec);
    vec=rotate(vec);
    vec=zip(vec);
    vec=rotate(vec);
    vec=rotate(vec);
    vec=rotate(vec);
    REP(i,vec.size()){
        cout<<vec[i]<<endl;
    }
    return 0;
}