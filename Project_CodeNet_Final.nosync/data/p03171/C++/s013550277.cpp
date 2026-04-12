#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define VV vector
#define pb push_back
#define bitc  __builtin_popcountl
#define m_p make_pair
#define inf 200000000000000
#define MAXN 1000001
#define eps 0.0000000001
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
string char_to_str(char c){string tem(1,c);return tem;}
// string to integer stoi()
// string to long long stoll()
// string.substr(position,length);
// integer to string to_string();

//////////////

#define S second
#define F first
#define int long long  

//////////

int a[10000];
int dp[3001][3001][2];

signed main()
{
    fastio;
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(i+j<n)
            {
                if(i==0){
                    dp[j][i][0]=a[j];
                    dp[j][i][1]=-a[j];
                }
                else{
                    dp[j][i][0]=max(dp[j][i-1][1]+a[i+j],dp[j+1][i-1][1]+a[j]);
                    dp[j][i][1]=min(dp[j][i-1][0]-a[i+j],dp[j+1][i-1][0]-a[j]);
                }
            }
        }
    }
    cout<<dp[0][n-1][0];
}