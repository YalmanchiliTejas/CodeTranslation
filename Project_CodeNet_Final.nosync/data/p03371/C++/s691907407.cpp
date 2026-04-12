#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long  ll;

#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
// constexpr ll mod = 1e9 + 7;

int main(){
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    ll ans=0;

    if(A+B>2*C){
        ans+=2*C*min(X,Y);
        int tmp=min(X,Y);
        X=X-tmp;
        Y=Y-tmp;
    }
    ans += X*min(A,2*C);
    ans += Y*min(B,2*C);

    cout << ans << endl;

        return 0;
}
