#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define erep(i,a,b) for(int i=a;i<=(int)(b);++i)
#define per(i,a,b) for(int i=(b);i>(a);--i)
#define eper(i,a,b) for(int i=((int)(a));i>=b;--i)
#define pb push_back
#define mp make_pair
#define INF (1<<28)-1
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int lcm(int a,int b){return a/gcd(a, b)*b;}

int n, k;
ll ans;
int main() {
 ios::sync_with_stdio ( false );
 cin.tie ( 0 );
    cin >> n >> k;
    erep(b, 1, n) {
        int p = n / b, r = n % b;
        ans += p * max(0, (b-k)) + max(0, r - k + 1);
        if (k == 0) ans--;
    }
    
    cout << ans << endl;
    return 0;
}
