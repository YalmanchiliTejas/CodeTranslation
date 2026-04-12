#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rrep(i,n) for (int i=(int)(n)-1; i>=0; --i)
#define debug(x) cerr << #x << " = " << x << "\n"
#define debugv(x) rep(i, x.size()) cerr << x[i] << (i == x.size() - 1 ? "\n" : " ")
#define all(x) x.begin(),x.end()
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = ((1LL << 30) + (1LL << 29));
const int MOD = 1000000007;
const int FIVE = 101010;

//=============================
int A,B,C,X,Y;
//=============================
void input()
{
    cin>>A>>B>>C>>X>>Y;
}
//=============================
void func(){}
//=============================
void solve()
{

    // ABピザを買う枚数でわける
    int mx = max(X,Y)*2;
    int ans = INF;
    int xcnt,ycnt;
    int xleft,yleft;
    int cost;
    for (int i=0; i<= mx; i += 2){
        xcnt=ycnt=i/2;
        cost = i*C;

        xleft = max(0LL,X-xcnt);
        yleft = max(0LL,Y-ycnt);

        cost += xleft*A + yleft*B;
        ans = min(ans, cost);
    }
    cout<<ans<<endl;
    
    
    


}
//=============================
signed main()
{
    input();
    solve();
    return 0;
}