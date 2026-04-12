/*
              ██████  ██████
              ██   ██ ██   ██
 Author ->    ██████  ██   ██
              ██      ██   ██
              ██      ██████
 
  nik is love.
  nik is motivation.
  Ek modulus aapki jindagi barbaad kar sakti hai
  Watch for integer overflows.
  A dream doesn't become reality through magic; it takes sweat, determination and hard work" — Colin Powell
 */
#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <functional>
#define pb                    push_back
#define ll                    long long
#define ss                       second
#define ff                        first
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define eps                   0.000000001
#define sz(a)                int((a).size())
#define all(c)               (c).begin(),(c).end()
#define present(c,x)         ((c).find(x) != (c).end())
#define cpresent(c,x)        (find(all(c),x) != (c).end())
#define pi                   pair<int,int>
#define pll                  pair<ll,ll>
#define endl                 '\n'

using namespace std;
vector<string> split(const string& s, char c) {
    vector<string> v; stringstream ss(s); string x;
    while (getline(ss, x, c)) v.emplace_back(x); return move(v);
}
template<typename T, typename... Args>
inline string arrStr(T arr, int n) {
    stringstream s; s << "[";
    for(int i = 0; i < n - 1; i++) s << arr[i] << ",";
    s << arr[n - 1] << "]";
    return s.str();
}

#define debug(args...) {__evars_begin(__LINE__); __evars(split(#args, ',').begin(), args);}

inline void __evars_begin(int line) { cerr << "#" << line << ": "; }
template<typename T> inline void __evars_out_var(vector<T> val) { cerr << arrStr(val, val.size()); }
template<typename T> inline void __evars_out_var(T* val) { cerr << arrStr(val, 10); }
template<typename T> inline void __evars_out_var(T val) { cerr << val; }
inline void __evars(vector<string>::iterator it) { cerr << endl; }

template<typename T, typename... Args>
inline void __evars(vector<string>::iterator it, T a, Args... args) {
    cerr << it->substr((*it)[0] == ' ', it->length()) << "=";
    __evars_out_var(a);
    cerr << "; ";
    __evars(++it, args...);
}
//using namespace __gnu_pbds;
//typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update> special_map;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef vector< int > vi;
typedef vector< vi > vvi;
int dx[8]={1,-1,0,0,-1,-1,1,1};
int dy[8]={0,0,-1,1,-1,1,-1,1};
const ll inf=1000000007;
vector<int> vis(500010,0),dis(500010,0),dis1(500010,-1),par(500010,0),col(500010,0);
vector<pair<int,int>> adj[500010];
int myrandom (int i) { return std::rand()%i;}
const int MAX=200100;
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //ifstream fin;
    //ofstream fout;
    //fin.open("input.txt");
    //fout.open("output.txt");
    //clock_t launch=clock();
    ll n,m,k;
    cin>>n>>m>>k;
    ll fct[MAX],inv[MAX],in[MAX];
    fct[0]=1;
    inv[0]=1;
    fct[1]=1;
    inv[1]=1;
    in[1]=1;
    for(int i=2;i<=200000;i++){
        fct[i]=(fct[i-1]*i)%inf;
        in[i]=(inf-((inf/i)*in[inf%i])%inf)%inf;
        inv[i]=(inv[i-1]*in[i])%inf;
    }
    ll tot=0;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            ll x1=((m-j)*(m-j+1))/2,x2=((j-1)*j)/2;
            ll y1=((n-i)*(n-i+1))/2,y2=((i-1)*i)/2;
            tot+=(((x1+x2)*n)%inf+((y1+y2)*m)%inf)%inf;
            tot%=inf;
        }
    }
    tot*=fct[n*m-2];
    tot%=inf;
    tot*=inv[k-2];
    tot%=inf;
    tot*=inv[n*m-k];
    tot%=inf;
    tot*=in[2];
    tot%=inf;
    cout<<tot<<endl;
    //clog<<((long double)(clock()-launch)/CLOCKS_PER_SEC)<<"\n";
}

