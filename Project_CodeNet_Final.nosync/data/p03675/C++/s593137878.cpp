#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define erep(i,a,b) for(int i=a;i<=(int)(b);++i)
#define per(i,a,b) for(int i=(a);i>(b);--i)
#define eper(i,a,b) for(int i=(a);i>=b;--i)
#define pb push_back
#define mp make_pair
#define INF (1<<30)-1
#define MOD 1000000007
#define all(x) (x).begin(),(x).end()
#define vii vector<int>
#define vll vector<long long>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int lcm(int a,int b){return a/gcd(a, b)*b;}

int n;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
    cin >> n;
    vii a(n);
    deque<int> b;
    rep(i, 0, n) {
        int a;
        cin >> a;
        if (i%2 == n%2) b.pb(a);
        else b.push_front(a);
    }
    rep(i, 0, n) {
        cout << b[i] << (i != n - 1 ? " " : "\n");
    }
    return 0;
}
