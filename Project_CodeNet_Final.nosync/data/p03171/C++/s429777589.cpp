#include <bits/stdc++.h>
#define N 3005

using namespace std;
int n, d[N][N][2];
long long A[N], F[N][N][2];

long long Magic(int l, int r, int play)
{
    if(r<l) return 0;
    if(d[l][r][play]) return F[l][r][play]; d[l][r][play] = 1;
    int role = play - (play^1);
    if(role>0) return F[l][r][play]=max(A[l]+Magic(l+1, r, play^1), A[r]+Magic(l, r-1, play^1));
    return F[l][r][play]=min(Magic(l+1, r, play^1)-A[l], Magic(l, r-1, play^1)-A[r]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++) cin>>A[i];
    cout<<Magic(1, n, 1);
    return 0;
}
