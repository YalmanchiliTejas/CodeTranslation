#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define MOD (1000000007)
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1}; // 移動方向

int a,b,c,x,y;

void input(){
    cin >> a >> b >> c >> x >> y;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    input();
    int ans = INF;
    for(int i=0;i<=100000;i++) ans = min(ans,2*c*i+max(0,x-i)*a+max(0,y-i)*b);
    cout << ans << endl;
    return 0;
}