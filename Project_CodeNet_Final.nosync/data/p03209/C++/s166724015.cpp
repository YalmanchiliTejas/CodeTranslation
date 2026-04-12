#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
//using namespace boost::multiprecision;
typedef long long int ll;
typedef long double ld;
#define MOD 1000000007
#define ALL(obj) (obj).begin(),(obj).end()
template<class T>inline bool chmax(T& a,T b){if (a<b){a=b;return 1;}return 0;}
template<class T>inline bool chmin(T& a,T b){if (a>b){a=b;return 1;}return 0;}
const long long INF = 1LL << 60;
bool pairCompare(const pair<double,ll>& firstElof, const pair<double,ll>& secondElof){
    return firstElof.first < secondElof.first;
}
bool pairCompareSecond(const pair<double,ll>& firstElof, const pair<double,ll>& secondElof){
    return firstElof.second < secondElof.second;
}
//四方向への移動ベクトル
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

struct edge{//グラフに使うヤツ
    ll from,to,cost;
};

typedef vector<vector<edge> > G;
ll gcd(ll a,ll b){
    if (a%b==0)return(b);
    else return(gcd(b,a%b));
}

ll n,x;
ll ans=0;
pair<ll,ll> p[51];
void bg(ll i){
    if (i==0){
        ans++;
        x--;
        return;
    }
    x--;
    if (x<=0){
        return;
    }
    if (x>p[i-1].first){
        x-=p[i-1].first;
        ans+=p[i-1].second;
    }else bg(i-1);
    if (x<=0){
        return;
    }
    ans++;
    x--;
    if (x<=0){
        return;
    }
    if (x>p[i-1].first){
        x-=p[i-1].first;
        ans+=p[i-1].second;
    }else bg(i-1);
    x--;
}

int main(){
    cin >> n >> x;
    p[0]=(make_pair(1,1));
    for (ll i=1;i<=50;i++){
        p[i]=make_pair(p[i-1].first*2+3,p[i-1].second*2+1);
    }
    bg(n);
    cout << ans << endl;
    return 0;
}
