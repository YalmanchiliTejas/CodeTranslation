#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout <<"DEBUG"<<" "<< #x << ":" << x << '\n'

//↓0-originか1-originでn回繰り返し
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   //0-indexed昇順
#define rep1(i,n) for(int i = 1; i <= ((int)(n)); i++) //1-indexed昇順
#define rrep(i,n) for(int i = ((int)(n)-1); i >= 0; i--)  //0-indexed降順
#define rrep1(i,n) for(int i = ((int)(n)); i >= 1; i--)   //1-indexed降順
#define all(x) (x).begin(),(x).end()

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vii; //2次元配列
typedef vector<ll> vll;
typedef pair<int, int> PII;

template<typename T>
using vec = vector<T>;
template<class T>
using maxheap = std::priority_queue<T>;
template<class T>
using minheap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

template<class T,class U> inline bool chmax(T &a, const U &b){if(a<b){a=b;return 1;}return 0;}
template<class T,class U> inline bool chmin(T &a, const U &b){if(a>b){a=b;return 1;}return 0;}

const ld PI = acos(-1.0L);
const ll infll = (1LL<<62)-1;
const int inf = (1<<30)-1;
const int mod = 1000000007;
//const int mod = 998244353;


/*FUNCs=================================================*/


/*MAIN==================================================*/
signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);   //cin cout 高速化
    //cout << fixed << setprecision(10);

    int n,m,a,b; cin >> n >> m;
    vii graph(n);
    rep(i,m) {
        cin >>a >>b;
        --a;--b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vi per(n-1);
    rep(i,n-1) per[i] = i+1;

    int ans = 0;
    do {
        for(int i = 0; i < n; ++i) {
            if(i==0) {
                bool can = false;
                for(auto u : graph[0]) if(u==per[0]) can = true;
                if(!can) break;
            }else {
                if(i==n-1) {
                    ++ans;
                    break;
                }
                bool can = false;
                for(auto u : graph[per[i-1]]) if(u==per[i]) can = true;
                if(!can) break;
            }
        }
    } while(next_permutation(all(per)));

    cout << ans << '\n';
}