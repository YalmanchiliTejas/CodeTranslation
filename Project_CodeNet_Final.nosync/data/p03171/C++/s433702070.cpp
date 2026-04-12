#include <bits/stdc++.h>
using namespace std; 
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair <int,int> PII;
typedef pair <ll, ll> PLL;
typedef pair <int,string> PIS;
typedef vector <int> vec;
typedef priority_queue<int> PQ;
#define endl '\n'
#define pi 3.141592653589793
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define fori(z,n)  for(int i=z;i<n;i++)
#define fork(z,n)  for(int k=z;k<n;k++)
#define forii(z,n) for(int i=z;i<=n;i++)
#define forkk(z,n) for(int k=z;k<=n;k++)
int maxElement(int arr[],int n)
{
    int maxi=arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]>maxi)
            maxi=arr[i];
    }
    return maxi;
}
int minElement(int arr[],int n)
{
    int mini=arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]<mini)
            mini=arr[i];
    }
    return mini;
}
string trim(const string& str)
{
    size_t first = str.find_first_not_of(' ');
    if (string::npos == first)
    {
        return str;
    }
    int last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}
int main() 
{ 
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;cin>>n;
    vector<ll> arr(n+1);
    for(int i=1;i<=n;i++) cin>>arr[i];
    ll dp[n+1][n+1];
    for(int i=n;i>=1;i--)
    {
        for(int k=i;k<=n;k++)
        {
            if(i==k)
                dp[i][k]=arr[k];
            else
                dp[i][k]=max(arr[i]-dp[i+1][k],arr[k]-dp[i][k-1]);
        }
    }
    cout<<dp[1][n]<<endl;
    cerr<<"Time elapsed"<<1.0*clock()/CLOCKS_PER_SEC<<"s\n";
    return 0;
}
