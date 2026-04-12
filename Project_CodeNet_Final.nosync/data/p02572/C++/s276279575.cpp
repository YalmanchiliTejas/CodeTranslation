#include <bits/stdc++.h>
using namespace std;
#define int long long
// #define min(a,b) a<b ? a:b
// #define max(a, b) a < b ? b : a
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)

#define pb push_back
#define pi 3.14159265358979323846

// int explore(vector<vector<int>> &adj,int x,int y,vector<int> &visited)
// {
//     if(x==y)
//     return 1;
//     visited[x]=1;
//     for(int i=0;i<adj[x].size();i++)
//     {
//         if(!visited[adj[x][i]])
//         {
//             if(explore(adj,adj[x][i],y,visited))
//             return 1;
//         }
//     }
//     return 0;
// }
bool valley(int p[], int k)
{
    if (p[k] < p[k - 1] && p[k] < p[k + 1])
        return true;
    return false;
}
bool peak(int p[], int k)
{
    if (p[k] > p[k - 1] && p[k] > p[k + 1])
        return true;
    return false;
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b); 
}

int32_t main()
{
    IOS;
    // int t;
    // cin>>t;
    // while(t--)
    // {
        int n;
        int x=1000000007;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        cin>>a[i];
        vector<int> v;
        int sum=0,z=0;
        int ctr=0;
        for(int i=1;i<n;i++)
        {
            sum+=a[i-1];
            ctr+=(sum%x*a[i]%x)%x;
        }
        cout<<ctr%x;
        
    // }
    

}
