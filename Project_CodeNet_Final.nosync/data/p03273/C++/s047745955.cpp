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
using P=pair<int,int>;
using PP=pair<int,P>;
using Pl=pair<ll,ll>;
using PPl=pair<ll,Pl>;
using vs=vector<string>;
#define fi first
#define se second
#define pb push_back
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}
template<class T>bool chmin(T &a,const T &b){if(a>b){a=b;return true;}return false;}
const ll MOD=1000000007LL;
const int INF=1<<30;
const ll LINF=1LL<<60;
int main(){
    int n,m;
    cin>>n>>m;
    vs vec;
    REP(i,n){
        string st;
        cin>>st;
        if(st==string(m,'.')){
            continue;
        }else{
            vec.pb(st);
        }
    }
    REP(i,vec.size()){
        REP(j,m){
            bool f=true;
            REP(k,vec.size()){
                if(vec[k][j]=='#'){
                    f=false;
                }
            }
            if(!f){
                cout<<vec[i][j];
            }
        }cout<<endl;
    }
    return 0;
}