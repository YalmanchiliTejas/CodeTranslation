//-----------------------//
//
// Welcome to my code!!
//
// Editor Koki_tkg
// Rating 512 (31/5/2020)
//
//-----------------------//

#include<bits/stdc++.h>
using namespace std;

#define IOS std::cin.tie(0);std::ios_base::sync_with_stdio(false)

#define ll      long long
#define vi      vector<int>
#define vp      vector<pair<int,int>>
#define vvi     vector<vector<int>>
#define vvp     vector<vector<pair<int,int>>>

#define sz(x) (int)x.size()
#define All(v) v.begin(),v.end()
#define output_s(s) printf("%s\n",(s).c_str())

#define rep(i,n)        for(int i=0;i<(int)(n);i++)
#define Rep(i,n,m)      for(int i=(int)(n);i<(int)(m);i++)
#define RepS(i,n,m)     for(int i=(int)(n);i<=(int)(m);i++)
#define RRepS(i,n,m)    for(int i=(int)(n);i>=(int)(m);i--)
#define SRepS(i,n,m)    for(int i=(int)(n);i*i<=(int)(m);i++)
#define RepA(x)         for(auto &item:(x))

void CINT(){} //@shibh308's template
template<class Head,class... Tail> void CINT(Head&& head,Tail&&... tail){cin>>head; CINT(move(tail)...);}    
#define CIN(...) int __VA_ARGS__;CINT(__VA_ARGS__)
#define LCIN(...) ll __VA_ARGS__;CINT(__VA_ARGS__)
#define SCIN(...) string __VA_ARGS__;CINT(__VA_ARGS__)
#define VCIN(x) for(auto &item:x) cin>>item

void OUT(){}
template<class Head,class...Tail> void OUT(Head&& head,Tail&&...tail){cout<<head<<(sizeof...(tail)?" ":"\n"); OUT(move(tail)...);}
#define COUT(...) OUT(__VA_ARGS__)

template<typename T>T GCD(T a,T b){return a%b==0?b:GCD(b,a%b);} //Greatest Common Divisor
template<typename T>T LCM(T a,T b){return a/GCD(a,b)*b;} //Least Common Multiple
template<class T>inline bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}
template<class T>inline bool chmin(T &a,const T &b){if(b<a){a=b;return true;}return false;}
template<class T>bool comp(T a,T b){return abs(a)<abs(b);} //Compare function
template<typename T>T POW(T x,T y,const T &m){T ret=1;while(y>0){if(y&1){ret*=x;ret%=m;}x*=x;x%=m;y>>=1;}return ret;} //POW(x, y, MOD)

void YES(bool f){printf(f?"YES\n":"NO\n");}
void Yes(bool f){printf(f?"Yes\n":"No\n");}
void Possible(bool f){printf(f?"Possible\n":"Impossible\n");}
void POSSIBLE(bool f){printf(f?"POSSIBLE\n":"IMPOSSIBLE\n");}

//---------------------Template------------------------//

//Prime Factorization 8/5/2020 update
//The result is stored in the array
void PrimeFactorize(ll num,vector<ll> &ret){
    vector<ll> prime(num+1,0);
    while(num%2==0){
        num /= 2;
        prime[2]++;
    }
    for(ll i=3;i<=num;i++){
        while(num%i==0){
            num /= i;
            prime[i]++;
        }
    }
    copy(prime.begin(),prime.end(),back_inserter(ret));
}

//Judge the prime number 8/5/2020 update
bool IsPrime(int x){
    if(x<2) return false;
    else if(x==2) return true;
    else if(x%2==0) return false;
    for(int i=3;i*i<=x;i+=2){
        if(x%i==0)return false;
    }
    return true;
}

//Meguru binary search 9/5/2020 update
//left < right
template<typename T>class BinarySearch{
    T _l;
    T _r;
    function<bool(T)> _f;
    public:
    BinarySearch(T left,T right,function<bool(T)>func){
        this->_l=left;
        this->_r=right;
        this->_f=func;
    }
    ~BinarySearch() = default;
    T calc(){
        while((this->_r-this->_l)>1){
            T middle=(this->_l+this->_r)/2;
            if(this->_f(middle)){
                this->_r=middle;
            }else{
                this->_l=middle;
            }
        }
        return this->_r;
    }
};

//Class Graph 18/5/2020 update
//indexed->0
//type->long long int
class Graph{
    struct edge{
        ll to;
        ll cost;
    };
    ll v; //vertex
    vector<list<edge>> G;
    vector<ll> preoder;
    vector<ll> postoder;
    vector<bool> seen;
    vector<ll> color;
    
    private:
    void dfs_sub(ll _n, ll &_f, ll &_l, const int _t){
        this->seen[_n]=true;
        this->preoder[_n]=_f++;
        list<edge>::iterator it;
        for(it=G[_n].begin();it!=G[_n].end();it++){
            if(this->seen[it->to]){
                if(_t >= 1) preoder[it->to]=_f++; 
                continue;
            }
            dfs_sub(it->to, _f, _l, _t);
        }
        this->postoder[_n] = _l++;
    }

    public:
    Graph(ll _v):G(_v){
        this->v = _v;
    };
    ~Graph(){
        vector<list<edge>>().swap(G);
        vector<ll>().swap(preoder);
        vector<ll>().swap(postoder);
        vector<bool>().swap(seen);
        vector<ll>().swap(color);
    };
    /**
     * @param _f    from
     * @param _t    to
     * @param _c    cost (default = 1)
    */
    void addEdge(ll _f, ll _t, ll _c = 1){
        G[_f].push_back(edge{_t,_c});
    }
    vector<ll> bfs(ll _f){
        queue<ll> que;
        vector<ll> dist(v,-1);
        vector<ll> ret(v,0);
        que.push(_f); dist[_f]=0;
        while(!que.empty()){
            ll _v=que.front(); que.pop();
            list<edge>::iterator it;
            for(it = G[_v].begin();it != G[_v].end();it++){
                if(dist[it->to]==-1){
                    que.push(it->to);
                    dist[it->to] = it->cost + dist[_v];
                    ret[it->to] = _v;
                }
            }
        }
        return ret;
    }
    /**
     * Dijkstra
     * @param _f Start position
    */
    vector<ll> Dijkstra(ll _f){
        const ll INF=1e18;
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> que;
        vector<ll> dist(v,INF);
        que.push(make_pair(0,_f));
        dist[_f]=0;
        while(!que.empty()){
            ll _v=que.top().second;
            que.pop();
            list<edge>::iterator it;
            for(it=G[_v].begin();it!=G[_v].end();it++){
                ll to=it->to;
                ll cost=it->cost;
                if(dist[to]>dist[_v]+cost){
                    dist[to]=dist[_v]+cost;
                    que.push(make_pair(dist[to],to));
                }
            }
        }
        return dist;
    }
    /**
     * @param type Undirected Graph (default) or Directed Graph (type >= 1)
    */
    void dfs(ll first,ll last,const int type=0){
        this->postoder.resize(this->v,-1);
        this->preoder.resize(this->v,-1);
        this->seen.resize(this->v,false);
        ll _f=first, _l=last;
        this->dfs_sub(0,_f,_l,type);
    }
    bool isCycle(){
        ll N=(ll)preoder.size()-1;
        for(ll it=0;it<N;it++){
            if(preoder[it]==-1)return true;
        }
        return false;
    }
    vector<ll> getPreoder(){
        return this->preoder;
    }
    vector<ll> getPostoder(){
        return this->postoder;
    }
};

//----------------------Library------------------------//

const int dx4[]={1,0,-1,0}, dx8[]={1,0,-1,0,1,-1,-1,1};
const int dy4[]={0,1,0,-1}, dy8[]={0,1,0,-1,1,1,-1,-1};
const int NMAX = 55;
const int INF = 1e9;
const long long LINF = 1e18;
const double EPS = 1e-10;
const int MOD = 1e9+7;
bool flag = false;
#define PI = 3.14159265358979323846

//----------------------Global-------------------------//


signed main(){
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int cost = a * x + b * y;
    chmin(cost, 2 * c * x + (x < y ? (y - x) * b : 0));
    chmin(cost, 2 * c * y + (x > y ? (x - y) * a : 0));

    cout << cost << endl;

    return 0;
}