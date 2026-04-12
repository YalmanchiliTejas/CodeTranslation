#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repeq(i,n) for(int (i)=0;(i)<=(int)(n);(i)++)
#define rep1(i,x,n) for(int (i)=(x);(i)<(int)(n);(i)++)
#define rep1eq(i,x,n) for(int (i)=(x);(i)<=(int)(n);(i)++)
#define rrep(i,x) for(int i=((int)(x)-1);i>=0;i--)
using namespace std;
using ll = long long;
using Int = long long;

const int MOD = 1000000007;
const ll INF = numeric_limits<ll>::max();
const int inf = 1e8;
typedef pair<int,int> P;

//少数点表示
//cout << std::fixed << std::setprecision(14) << 値

int main(){
    cin.tie( 0 ); ios::sync_with_stdio( false );
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    int ans = a*x + b*y;
    int half=0;
    int rec = 0;
    while(half<=max(x,y)){
        rec = 2*c*half + a*(max(0,x-half)) + b*(max(0,y-half));
        ans = min(ans,rec);
        half++;
    }
    
    cout << ans << endl;
    return 0;
}