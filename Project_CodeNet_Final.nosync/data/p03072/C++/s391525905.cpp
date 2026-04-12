#include <bits/stdc++.h> 
using namespace std;
const long long int INF = INT64_MAX;
const long long int Mod = 1000000007;
using ll = long long int; /*long long int は64bit*/
using vi = vector<int>;using Vi = vector<long long int>;using matrix = vector<vector<ll> >;using Pair = pair<ll,ll>;
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define mt make_tuple
#define all(x) (x).begin(),(x).end()
#define rep(i,N) for(long long int i=0;i<N;i++) 
#define rev(i,N) for(long long int i=N-1;i>=0;i--) /*N-1からスタート*/
#define np nullptr
template<class T,class T2>bool chmax(T &former, const T2 &b) { if (former<=b) { former=b; return true; } return false; }
template<class T,class T2>bool chmin(T &former, const T2 &b) { if (b<former) { former=b; return true; } return false; }
template<class T>T sqar(T x){ return x*x; } /*sqrt(x)は平方根*/
#define Sort(v) std::sort(v.begin(), v.end(), std::greater<decltype(v[0])>()) /*降順↓でVをソート*/
#define fill(x,num) memset(x,num,sizeof(x));
template<class T1,class T2>bool p_compare(const pair<T1,T2> fir,const pair<T1,T2> sec){ return fir.second < sec.second; }
bool p_comp(const Pair fir,const Pair sec){return p_compare<ll,ll>(fir,sec);}
template<class T1,class T2>bool pcompare(pair<T1,T2> fir,pair<T1,T2> sec){ return !p_comp(fir,sec); }
bool pcomp(const Pair fir,const Pair sec){return pcompare<ll,ll>(fir,sec);}
/*sort(all(v),p_compare<ll,ll> 又は p_comp)で↑ソート , pcompは↓ソート*/

//////////////////////////^^ *Emile ^^^//////////////////////////////////////////////////////
//Snipet -> Caps Lock


ll n;
ll hh[1000];

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    cin>>n;
    rep(i,n){
        cin>>hh[i];
    }
    ll ans = 0;
    bool key;
    rep(i,n){
        if(i==0)ans++;
        key = true;
        if(i!=0)rep(j,i){
            if(hh[j]>hh[i])key = false;
        }
        if(i!=0 && key)ans++;
    }
    cout<<ans<<endl;
    return 0;
}