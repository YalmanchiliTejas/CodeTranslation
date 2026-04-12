
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long
#define mod 1000000007
#define do double
#define loop(i,n) for(int i=0;i<n;i++)
#define lop(a,b) for(int i=a;i<=b;i++)
#define pb push_back
#define mkp make_pair

typedef vector <int> vi;
typedef map <int,int> mii;
typedef set <int> si;
typedef pair <int,int> pii;
typedef unordered_map <int,int> um;
typedef unordered_set <int> us;
typedef multiset <int> ms;
typedef vector < pair <int,int> > vpii;
// Driver code 
int main() 
{ 
    int n;
    cin>>n;
    ll a[n],sum=0;
       loop(i,n)
       {  cin>>a[i];
          sum+=a[i];
       }

    ll dp[n+1][n+1]={};
    for(int l=1;l<=n;l++)
    {
        for(int i=0;i<n-l+1;i++)
        {
            int j=i+l-1;
            if(i==j)
                dp[i][j]=a[i];
            else if(j-i==1)
                dp[i][j]= max(a[i],a[j]);
            else dp[i][j] = max(a[i] + min(dp[i+2][j],dp[i+1][j-1]),a[j] + min(dp[i][j-2],dp[i+1][j-1]));
        }
    }
    
    cout<<2*dp[0][n-1]-sum<<"\n";

} 

