#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define PI 3.14159265358979323846
#define int long long
constexpr int INF = numeric_limits<int>::max() / 2;
constexpr long long INFL = numeric_limits<long long>::max() / 2;
constexpr int MOD = 1000000007;
using Graph = vector<vector<int>>;



signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin>>N;
    int A[N];
    rep(i,N){
        cin>>A[i];
    }
    sort(A,A+N);
    int ans=0;
    int co=0;
    if(N%2==0){
        int x=N/2-1;
        rep(i,x){
            ans-=2*A[i];
        }
        for(int i=N-1;i>N-1-x;i--){
            ans+=2*A[i];
        }
        ans+=A[x+1]-A[x];
    }else{
        int x=(N-2)/2;
        rep(i,x+1){
            ans-=2*A[i];
        }
        for(int i=N-1;i>N-1-x;i--){
            ans+=2*A[i];
        }
        ans+=A[x]+A[x+2];
        ans+=max(A[x+2]-A[x+1],A[x+1]-A[x]);
    }
    cout << ans << endl;



}
