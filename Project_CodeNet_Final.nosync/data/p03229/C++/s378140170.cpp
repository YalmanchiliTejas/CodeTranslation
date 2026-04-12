#include <bits/stdc++.h>
using namespace std;
#define int long long
using P = pair<int,int>;
const int INF = 1e18;
const int MOD = 1e9+7;
#define put(n) cout<<(n)<<endl
#define rep(i,N) for(int(i)=0;(i)<(N);++(i))
#define all(v) (v).begin() , (v).end()
#define rall(v) (v).rbegin() , (v).rend()
#define pb(n) push_back(n)

signed main(){
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i,N) cin >> A[i];

    sort(rall(A));

    int ans = 0, res = 0;
{
    int n = A.size() / 2;

    rep(i,n) ans += A[i]*2;
    if(A.size() % 2 == 0) ans -= A[n - 1];

    for(int i = n; i < A.size(); i++) ans -= A[i]*2;
    ans += A[n];
    if(A.size() % 2 == 1) ans += A[n + 1];
}
{
    int n = A.size() / 2 + A.size() % 2;

    rep(i,n) res += A[i]*2;
    res -= A[n - 1];
    if(A.size() % 2 == 1 && n > 1) res -= A[n - 2];

    for(int i = n; i < A.size(); i++) res -= A[i]*2;
    if(A.size() % 2 == 0) res += A[n];
    
}
    cout <<  max(ans ,res) << endl;
}
