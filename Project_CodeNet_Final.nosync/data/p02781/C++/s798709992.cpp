#define __mode_debug__
/*   ξ
     ll
   ＿ll＿
 ／  ∞  ＼
│*  Ａ  *│
│*  Ｃ  *│
│*  祈  *│
│*  願  *│
│*      *│
 ￣￣￣￣￣    */
//C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
#ifdef __mode_debug__
    #define DBG
#else
    #define DBG if(false)
#endif

#define LLINF (1LL<<60)
using ll = long long;
#define mod (1e9+7)

#define whole(a) (a).begin(),(a).end()
#define rwhole(a) (a).rbegin(),(a).rend()

#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define rrepd(i,a,b) for(int i=(a);i>=(b);i--)
#define each(itr,ds) for(auto itr=(ds).begin();itr!=(ds).end();itr++)

template<typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

template < typename T > inline string toString( const T &a ) { ostringstream oss; oss << a; return oss.str(); }

//DUMP
//  ostream vector<T> , vector<vector<T>> , set<T> ,queue<T> , priority_queue<T> , pair<T,U> , map<T,U>
template<class T> ostream& operator<<(ostream&os,vector<T>&vec){os<<"{ ";rep(i,vec.size()) os<<((i==0)?"":", ")<<i<<":"<<vec[i];os<<" }";return os;}
template<class T> ostream& operator<<(ostream&os,vector<vector<T>>&vec){os<<"{"<<endl;rep(i,vec.size())os<<"\t   "<<i<<":"<<vec[i]<<((i==vec.size()-1)? "":",")<<endl;os<<"\t }";return os;}
template<class T> ostream& operator<<(ostream&os,set<T>&p){os<<"{ ";each(itr,p)  os<<((itr==p.begin())?"":", ")<<*itr;os<<" }";return os;}
template<class T> ostream& operator<<(ostream&os,queue<T>&p){queue<T> q(p);os<<"[< "<<(q.empty()?" <]":"");while(!q.empty()){os<<q.front();q.pop();os<< (q.empty() ? " <]" : ", ");}return os;}
template<class T> ostream& operator<<(ostream&os,priority_queue<T>&p){priority_queue<T> q(p);os<<"[< "<<(q.empty()?" <]":"");while(!q.empty()){os<<q.top();q.pop();os<< (q.empty() ? " <]" : ", ");}return os;}
template<class T,class U> ostream& operator<<(ostream&os,pair<T,U>&p){os<<"("<<p.first<<","<<p.second<<")";return os;}
template<class T,class U> ostream& operator<<(ostream&os,map<T,U>&p){os<<"{ ";each(itr,p)os<<((itr==p.begin())?"":", ")<<itr->first<<":"<<itr->second;os<<" }";return os;}
void dump_f(string &nm,char t){cerr<<endl;}
template<class T,class... Ts> void dump_f(string &nm,char t,T &&x,Ts&&... ts){int l=nm.find_first_of(',');string name(nm,0,l),nx(nm,l+1,-1);if(t=='\n') cerr<<"  "<<name<<"\t: "<<x<<t;else cerr << name<<": "<<x<<","<<t;dump_f(nx,t,forward<Ts>(ts)...);}
template<class... Ts> void dump_m(int &&ln,string &&nm,char t,Ts&&... ts){cerr<<"[ln: "<<ln<<"]"<<t;dump_f(nm,t,forward<Ts>(ts)...);}
#define dump(...) DBG dump_m(__LINE__,#__VA_ARGS__,'\n',__VA_ARGS__)
#define dl(...) DBG dump_m(__LINE__,#__VA_ARGS__,'\t',__VA_ARGS__)

#define lower_bound_idx(V,c) distance(V.begin(),lower_bound(whole(V),c))


int main() {
    ios::sync_with_stdio(false);//stdout<=>cout
    cin.tie(nullptr);//cin<=>cout


    string S;
    int K;
    cin >>S>>K;
    int N=S.size();


    //桁DP
    ll dp[101][2][4]={0};//[KETA][<S ?][ how times "!=0" ]
    dp[0][0][0]=1;
    rep(i,N){
        const int D=S[i]-'0';
        rep(issmlr,2)rep(k,K+1)rep(d,10){
            if(!issmlr && D < d)continue;
            const int yo = (issmlr || d < D) ;
            if(d==0){
                        dp[i+1][yo][k]   += dp[i][issmlr][k];
            }else{
                if(k<K) dp[i+1][yo][k+1] += dp[i][issmlr][k]; 
            }
        }
    }
    ll ans=dp[N][0][K]+dp[N][1][K];


    cout << ans <<endl;


    return (0);
}