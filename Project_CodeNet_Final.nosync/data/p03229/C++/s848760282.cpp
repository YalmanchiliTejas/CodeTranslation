#include<bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<n;i++)

int N;
int A[100010];

signed main()
{
    cin >> N;
    rep(i, N)cin >> A[i];

    sort(A, A + N);

    int l = 0, r = N - 1;
    int ans = A[N - 1] - A[0];
    for(int i = 0;;i++)
    {
        l++;
        r--;
        if(l > r)break;
        if(l == r)
        {
            ans += max(abs(A[l] - A[l - 1]), abs(A[r] - A[r + 1]));
            break;
        }
        ans += abs(A[l] - A[r + 1]) + abs(A[r] - A[l - 1]);
    }

    cout << ans << endl;

    return 0;
}