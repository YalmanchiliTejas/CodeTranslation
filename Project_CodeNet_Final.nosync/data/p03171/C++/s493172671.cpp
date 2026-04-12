#include <bits/stdc++.h>
using namespace std;
#define int long long

const int nax=3005;
int dp[nax][nax];

#undef int 
int main() {
#define int long long
    int n;
    cin >> n;

    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];

    for(int L=n-1; L>=0; L--)
    {
        for(int R=L;R<n;R++)
        {
            if(L==R)
            {
                dp[L][R]=a[L];
            }
            else
            {
                dp[L][R]=max(a[L]-dp[L+1][R], a[R]-dp[L][R-1]);
            }
            
        }
    }
    cout << dp[0][n-1] << endl;
}