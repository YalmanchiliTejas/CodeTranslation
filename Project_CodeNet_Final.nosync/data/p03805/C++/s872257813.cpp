#include <bits/stdc++.h>
#define itn int
#define REP(i, n) for (ll i = 0; i < n; i++)
#define IREP(i, n) for (ll i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (ll i = a; i < b + 1; i++)
#define all(v) v.begin(), v.end()
#define SENTINEL 2000000000
#define NIL -1
using namespace std;
typedef long long ll;

const ll INF = 1LL << 60;
const ll MOD = 1000000007;
template <class T>inline bool chmin(T &a, T b){if(a>b){a=b;return true;}return false;}
template <class T>inline bool chmax(T &a, T b){if(a<b){a=b;return true;}return false;}
vector<vector<int>> v(8);
int n;
int func(vector<bool> y,int x,int count){
    vector<bool> w=y;
    w[x]=true;
    int tmp=0;
    if(count==n){
        return 1;
    }
    for(auto& i:v[x]){
        if(!w[i]){
            tmp+=func(w,i,count+1);
        }
    }
    return tmp;
}
int main()
{
    int m;
    cin >> n >> m;
    REP(i,m){
        int a,b;
        cin >> a >> b;
        a--;b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<bool> w(n,false);
    int ans=func(w,0,1);
    cout << ans << endl;
}