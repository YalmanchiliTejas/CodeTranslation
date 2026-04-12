#include <bits/stdc++.h>
using namespace std;
#define oo 666666666
#define ll long long
#define ld long double

ll DP[3001][3001];
ll A[3001];

ll solve(int l, int r)
{
    if(l > r)return 0;
    if(l==r)return A[r];
    if(DP[l][r]!=0)return DP[l][r];
    return DP[l][r]=max(A[l] + min(solve(l+1,r-1),solve(l+2,r)), A[r] + min(solve(l+1,r-1),solve(l,r-2)));
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>A[i];

    cout<<2*solve(1,n) - accumulate(A, A+n+1, 0LL);
}
