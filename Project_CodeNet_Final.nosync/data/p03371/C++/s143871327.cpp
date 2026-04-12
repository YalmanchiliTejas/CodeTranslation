#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    int A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;
    int ans = A*X+B*Y;
    for(int i=0;i<=X+Y;i++){
        int tmp = 2*C*i + max(0,X-i)*A + max(0,Y-i)*B;
        ans = min(ans,tmp);
    }
    cout << ans << endl;
    return 0;
}