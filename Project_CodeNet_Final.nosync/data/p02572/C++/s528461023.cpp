#include<bits/stdc++.h>
using namespace std;
#define lc "\n"
#define fast_io ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(0)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define int long long
#define c(a,n) for(int i = 0; i < n; i++) cin >> a[i];
#define ffor(n) for(int i = 0; i < n; i++)
#define float long double
typedef vector<int> vi;
typedef vector<float> vf;
typedef vector<vi> vii;
typedef vector<string> vs;
typedef vector<long long> vll;
typedef map<string,int> msi;
typedef map<int,int> mii;
typedef unordered_map<string,int> umsi;
 
 
int32_t main()
{
    fast_io;
    int n;
    cin>>n;
    vi a(n);
    c(a,n); 
    vi pre(n);
    int m=1e9+7;
    pre[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--)pre[i]=((a[i]%m)+(pre[i+1]%m))%m;
    int ans=0;
    for(int i=1;i<n;i++)
    ans=(ans%m + ((a[i-1]%m)*(pre[i]%m))%m)%m;
    cout<<ans;
    return 0;
}