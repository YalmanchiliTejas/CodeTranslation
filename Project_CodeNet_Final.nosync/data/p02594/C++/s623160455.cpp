#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define intarr(arr, n)  ll arr[n];  for (ll i = 0; i < n; i++)  cin >> arr[i]
#define inpvec(vec,n) for(ll i=0;i<n;i++){ll var;cin>>var;vec.push_back(var);}
#define ff first
#define ss second
#define pb push_back
#define mkp make_pair
#define vec vector<ll>
#define pi pair<ll,ll>
#define changeline cout<<endl
#define loop(i,a,b) for(ll i=a;i<b;i++)
#define rev(i,a,b) for(ll i=a;i>=b;i--)
#define all(v) v.begin(),v.end()
#define mod2 998244353
#define NO cout << "NO" <<endl
#define YES cout << "YES" <<endl
#define mem(arr,val) memset(arr,val,sizeof(arr));
const ll mod=1e9+7;
#define piii 3.14159265358979323846264338327950
#define print(a, n, m)     for (ll i = n; i < m; i++) {  cout << a[i] << " "; }  cout << endl
#define con continue

bool prime(ll n) 
{ 
    if (n <= 1)  return false; 
    if (n <= 3)  return true; 
    if (n%2 == 0 || n%3 == 0) return false; 
  
    for (ll i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
           return false; 
  
    return true; 
}
bool isPerfectSquare(ll x) {   
  long double sr = sqrt(x); 
  return ((sr - floor(sr)) == 0); 
} 
bool subsequence_checker(string str1, string str2, ll m, ll n) 
{ 
    if (m == 0) return true; 
    if (n == 0) return false; 
    if (str1[m-1] == str2[n-1]) 
        return subsequence_checker(str1, str2, m-1, n-1); 
    return subsequence_checker(str1, str2, m, n-1); 
}
bool cmp(const pair<int,int> &a,  const pair<int,int> &b) 
{ 
    if(a.ff == b.ff)
        return a.ss < b.ss;
    return (a.ff > b.ff); 
}
//////////////////////////////////////////////////// Lets Do It ////////////////////////////////////////////////////////



void solve()
{

    ll n;
    cin>>n;

    if(n>=30)
        cout<<"Yes";
    else
        cout<<"No";

    return;
}
 
int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
    IOS;
    ll t;
    //cin>>t;
    t=1;

    while(t--){
        solve();
        //cout<<endl;
    }

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
} 