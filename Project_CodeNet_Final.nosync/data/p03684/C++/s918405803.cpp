#include <bits/stdc++.h>
using namespace std;
/*{{{*/  //template
#define rep(i,n) for(int i=0;i<n;i++)
constexpr int INF = numeric_limits<int>::max()/2;
constexpr long long LINF = numeric_limits<long long>::max()/3;
//#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define sz(x) (int)(x).size()
#define debug(x) cerr<<#x<<":"<<x<<endl
#define debug2(x,y) cerr<<#x<<","<<#y":"<<x<<","<<y<<endl
//struct fin{ fin(){ cin.tie(0); ios::sync_with_stdio(false); } } fin_;
struct Double{ double d; explicit Double(double x) : d(x){} };
ostream& operator<<(ostream& os,const Double x){ os << fixed << setprecision(20) << x.d; return os; }
template<typename T> ostream& operator<<(ostream& os,const vector<T>& vec){ os << "["; for(const auto& v : vec){ os << v << ","; } os << "]"; return os; }
template<typename T,typename U> ostream& operator<<(ostream& os,const pair<T,U>& p){ os << "(" << p.first << ","<< p.second <<")"; return os; }
template<typename T> ostream& operator<<(ostream& os,const set<T>& st){ os<<"{"; for(T v:st) os<<v<<","; os <<"}"; return os; }
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
ll gcd(ll a,ll b){ if(b==0) return a; else return gcd(b,a%b); }
//constexpr double eps = 1e-14; 
constexpr double eps = 1e-10; 
constexpr ll mod = 1e9+7;
const int dx[]={1,0,-1,0} ,dy[] = {0,1,0,-1};
/*}}}*/

int N;
vector<ll> x,y;
bool vis[100100];


template<typename T,typename U> ostream& operator<<(ostream& os,const map<T,U>& p){
    os << "{";
    for(auto v : p){
        os <<"(" << v.fi << "," << v.se <<"),";
    }
    os << "}";
}

using P = tuple<ll,ll,int>;

int main(){
    cin >> N;
    x.resize(N);
    y.resize(N);
    vector<P> v1(N),v2(N);
    rep(i,N){
        cin >> x[i] >> y[i];
        v1[i] = make_tuple(x[i],y[i],i);
        v2[i] = make_tuple(y[i],x[i],i);
    }

    sort(all(v1));
    sort(all(v2));
    v1.erase(std::unique(v1.begin(), v1.end()), v1.end());
    v2.erase(std::unique(v2.begin(), v2.end()), v2.end());

    map<ll,map<ll,ll>> mp;
    for(int i=0;i<N-1;i++){
        int idx1,idx2;
        idx1 = get<2>(v1[i]);
        idx2 = get<2>(v1[i+1]);
        ll x1,x2;
        x1 = get<0>(v1[i]);
        x2 = get<0>(v1[i+1]);
        ll y1,y2;
        y1 = get<1>(v1[i]);
        y2 = get<1>(v1[i+1]);
        mp[idx1][idx2] = min(abs(x1-x2),abs(y1-y2));
        mp[idx2][idx1] = min(abs(x1-x2),abs(y1-y2));
    }
    for(int i=0;i<N-1;i++){
        int idx1,idx2;
        idx1 = get<2>(v2[i]);
        idx2 = get<2>(v2[i+1]);
        ll x1,x2;
        x1 = get<0>(v2[i]);
        x2 = get<0>(v2[i+1]);
        ll y1,y2;
        y1 = get<1>(v2[i]);
        y2 = get<1>(v2[i+1]);
        if(!mp[idx1].count(idx2))
            mp[idx1][idx2] = min(abs(x1-x2),abs(y1-y2));
        else
            mp[idx1][idx2] = min(mp[idx1][idx2],min(abs(x1-x2),abs(y1-y2)));
        mp[idx2][idx1] = mp[idx1][idx2];
    }

    vector<ll> dis(N,INF);
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> que;
    que.push({0,0});

    while(!que.empty()){
        auto p = que.top();
        que.pop();
        ll d = p.fi;
        int v = p.se;
        if(dis[v]<d){
            continue;
        }
        dis[v] = d;
        //cout << "pop " << v <<endl;
        for(auto q : mp[v]){
            int nv = q.fi;
            ll nd = q.se;
            if(dis[nv] != INF) continue;

            if(dis[nv] > nd){
                //cout << "push " << nv << " " << nd << endl;
                que.push(make_pair(nd,nv));
            }
        }
    }

    //cout << dis << endl;
    ll ans = 0;

    ans = accumulate(all(dis),0ll);
    cout << ans << endl;
}
