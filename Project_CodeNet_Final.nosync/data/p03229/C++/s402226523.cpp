#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define rep(i, n) for(ll i=0; i<(ll)(n); i++)
#define repd(i, n) for(ll i=n-1; 0<=i; i--)
#define FOR(i, a, b) for(ll i=a; i<(ll)(b); i++)
#define FORD(i, a, b) for(ll i=b-1; (ll)(a)<=i; i--)
#define ALL(x) x.begin(), x.end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
string YES[2] = {"NO", "YES"};
string yes[2] = {"No", "Yes"};

int main(){
    ll n;   cin >> n;
    vector<ll> a(n);
    rep(i, n)   cin >> a[i];
    sort(ALL(a));
    deque<ll> que;
    rep(i, n)   que.push_back(a[i]);
    deque<ll> res;
    res.push_back(a[0]); que.pop_front();   
    while(!que.empty()){
        ll pre=que.front(), suf=que.back();
        ll rpre = res.front(), rsuf=res.back();
        if(max(abs(pre-rpre), abs(suf-rpre))>max(abs(pre-rsuf), abs(suf-rsuf))){
            if(abs(pre-rpre)<abs(suf-rpre)){
                res.push_front(suf);    que.pop_back();
            }else{
                res.push_front(pre);    que.pop_front();
            }
        }else{
            if(abs(pre-rsuf)<abs(suf-rsuf)){
                res.push_back(suf);    que.pop_back();
            }else{
                res.push_back(pre);    que.pop_front();
            }
        }
    }
    ll sum=0, pre=res.front();  res.pop_front();

    while(!res.empty()){
        
        ll x=res.front();   res.pop_front();
        //cout << x << ' ';
        sum += abs(x-pre);
        pre = x;
    }
    cout << sum << endl;
}
