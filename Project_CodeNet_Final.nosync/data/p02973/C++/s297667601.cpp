#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<list>
#include<set>
#include<map>
#include<utility>
#include<cmath>
#include <iomanip>
#include<stack>
#include<queue>


#define rep(i,x) for(int i=0;i<(int)(x);i++)
#define reps(i,x) for(int i=1;i<=(int)(x);i++)
#define rrep(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define rreps(i,x) for(int i=((int)(x));i>0;i--)

#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define INF 2e9

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef long long ll;
typedef long double ld;
typedef std::pair<ll, ll> P;
int gcd(int a,int b){return b?gcd(b,a%b):a;}

using namespace std;

int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> m;
    rep(i, n) cin >> a[i];

    ll cnt = 0;
    rep(i, n){
        if(i == 0){
            m.push_back(a[i]);
            cnt++;
            continue;
        }
        if(upper_bound(all(m), a[i], greater<ll>())-m.begin() == m.size()){
            m.push_back(a[i]);
            cnt++;
        }else{
            ll itr = upper_bound(all(m), a[i], greater<ll>())-m.begin();
            m[itr] = a[i];
        }
    }
    cout << cnt;
}