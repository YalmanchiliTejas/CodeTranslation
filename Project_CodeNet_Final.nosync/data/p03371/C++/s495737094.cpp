#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
constexpr int INF = numeric_limits<int>::max() / 2;
constexpr long long INFL = numeric_limits<long long>::max() / 2;
constexpr int MOD = 1000000007;


int  main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    long long A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;

    
    long long sum=0;
    long long x,y;
    int q=max(X,Y);
    long long ans=INFL;
    for(int i=0;i<2*q+1;i+=2){
        x=max(0LL,X-i/2);
        y=max(0LL,Y-i/2);
        ans=min(ans,i*C+x*A+y*B);
    }
    cout << ans << endl;



}