#include<bits/stdc++.h>
using namespace std;
#define MAX 3005
long long dp[MAX][MAX];
int main()
{
    long long n;
    cin>>n;
    vector<long long> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int R=n-1;R>=0;R--)
    {
        for(int L=R;L<n;L++){
            if(L==R)
                dp[R][L]=arr[L];
            else
                dp[R][L]=max(arr[R]-dp[R+1][L],arr[L]-dp[R][L-1]);
        }
    }
    cout<<dp[0][n-1]<<endl;
}