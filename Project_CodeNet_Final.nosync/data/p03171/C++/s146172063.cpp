#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<set>
#include<map>
#define int long long
#define MOD 1000000007
#define br break
#define rem 500009
#define PI 3.1415926535
#define INF 1e18 
#define ve vector
#define mp make_pair
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define mxe(v) *max_element(v.begin(),v.end())
#define mne(v) *min_element(v.begin(),v.end())
#define bs binary_search
#define lb lower_bound
#define ub upper_bound
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rep(g, i, n) for (int g = i; g < n; g++)
#define rev(g, n, i) for (ll g = n - 1; g >= i; g--)
using namespace std;

// Uncomment for using Graph Theory Approaches


// vector<int> adj[300005]; // adjacency list representation
//queue<int> q;
// bool used[300005]={false};
// int d[300005], p[300005];
// queue<int> q;


// void bfs(int s,int n)
// {
//     rep(i,0,n)
//         used[i]=false,d[i]=INT_MAX,p[i]=-1;
//     q.push(s);
//     used[s] = true;
//     p[s] = -1;
//     while (!q.empty()) 
//     {
//         int v = q.front();
//         q.pop();
//         for (int u : adj[v]) 
//         {
//             if (!used[u]) 
//             {
//                 used[u] = true;
//                 q.push(u);
//                 d[u] = d[v] + 1;
//                 p[u] = v;
//             }
//         }
//     }
// }
// printBfs(int s, int u)
// {
//     if (!used[u]) 
//     {
//         cout << "No path!";
//     } 
//     else 
//     {
//         vector<int> path;
//         for (int v = u; v != -1; v = p[v])
//             path.push_back(v);
//         reverse(path.begin(), path.end());
//         cout << "Path: ";
//         for (int v : path)
//             cout << v << " ";
//     }
// }
// void dfs(int v) {
//     visited[v] = true;
//     for (int u : adj[v]) {
//         if (!visited[u])
//             dfs(u);
//     }
// }




//If we have to restore and display the shortest path from the source to some vertex u, it can be done in the following manner:

//void fastscan(int &number)// For fast input
//{ 
//    //variable to indicate sign of input number 
//    bool negative = false; 
//    register int c; 
//  
//    number = 0; 
//  
//    // extract current character from buffer 
//    c = getchar(); 
//    if (c=='-') 
//    { 
//        // number is negative 
//        negative = true; 
//  
//        // extract the next character from the buffer 
//        c = getchar(); 
//    } 
//  
//    // Keep on extracting characters if they are integers 
//    // i.e ASCII Value lies from '0'(48) to '9' (57) 
//    for (; (c>47 && c<58); c=getchar()) 
//        number = number *10 + c - 48; 
//  
//    // if scanned input has a negative sign, negate the 
//    // value of the input number 
//    if (negative) 
//        number *= -1; 
//}
//int fast_exp(int base, int exp) {
//    int res=1;
//    while(exp>0) {
//       if(exp%2==1) res=(res*base)%MOD;
//       base=(base*base)%MOD;
//       exp/=2;
//    }
//    return res%MOD;
//}
//void SieveOfEratosthenes(int n) 
//{ 
//    bool prime[n+1]; 
//    memset(prime, true, sizeof(prime)); 
//  
//    for (int p=2; p*p<=n; p++) 
//    { 
//        if (prime[p] == true) 
//        { 
//            for (int i=p*p; i<=n; i += p) 
//                prime[i] = false; 
//        } 
//    } 
//    for (int p=2; p<=n; p++) 
//       if (prime[p]) 
//          cout << p << " "; 
//}
//void find(int n) // Find powers of prime factorization of number
//{ 
//    bool prime[n+1]; 
//  memset(prime, true, sizeof(prime)); 
//  for (int p=2; p*p<=n; p++) 
//    { 
//        if (prime[p] == true) 
//        { 
//            for (int i=p*p; i<=n; i += p) 
//                prime[i] = false; 
//        } 
//    }
//    vector<int> powers;
//    for (int p=2; p<=n; p++) 
//    {
//      if (prime[p] && n%p==0)
//      {
//          int count=0;
//          while(n%p==0 && n!=0)
//          {
//              n=n/p;
//              count++;
//          }
//          powers.pb(count);
//      }
//  }
//    for(int i=0;i<powers.size();i++)  
//      cout<<powers[i]<<" "; 
// }

//===================================================================================================================
// THE FIRST PRINCIPLE, IS THAT YOU MUST NOT FOOL YOURSELF, AND YOU ARE THE EASIEST PERSON TO FOOL- Richard Feynman.
// ******************************************************************************************************************
// CODE BEGINS HERE:
void solve()
{
    int n;
    cin>>n;
    int a[n];
    rep(i,0,n)
    	cin>>a[i];
    int dp[n][n];
    for(int l=n-1;l>=0;l--)
    {
    	for(int r=l;r<n;r++)
    	{
    		if(l==r)
    			dp[l][r]=a[l];
    		else
    			dp[l][r]=max(a[l]-dp[l+1][r],a[r]-dp[l][r-1]);

    	}
    }
    cout<<dp[0][n-1]<<endl;

}

 signed main() 
{ 
//#ifndef ONLINE_JUDGE
    //  freopen("input.txt","r",stdin);
    //  freopen("output.txt","w",stdout);
//#endif
    FAST;
    solve();
    return 0; 
} 





