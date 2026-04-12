#include <bits/stdc++.h>
 
#define ll          long long
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define vll         vector<ll>
#define all(a)      (a).begin(),(a).end()
#define lol         1000000007
#define rep(i,a,b)    for(int i=a;i<b;i++)
#define SIZE        1000005
#define debug(x)    cerr << #x << " = " << x << endl;
#define F             first
#define S             second
#define endl        '\n'
#define deci(n)     cout<<fixed<<setprecision(n);
const double         pi=acos(-1.0);


using namespace std;

void MOD(ll &x)
{
    if (x >= lol) x -= lol;
    if (x < 0) x += lol;
}

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }




void solve()
{
    int n;
    cin>>n;
    ll arr[n];
    rep(i,0,n) cin>>arr[i];
    sort(arr,arr+n);
    ll ans[n];
    int i = 1;
    while(2*i-1 < n)
    {
        ans[2*i-1] = arr[n-i];
        i++;
    }
    int k = n-i;
    int j = 0;
    i = 2;
    while(i<n)
    {
        ans[i] = arr[j];
        j++;
        i += 2;
    }
    ans[0] = arr[j];
    ll boii = -ans[0];
    int sign = 1;
    rep(i,1,n-1)
    {
        boii += sign*2*ans[i];
        sign *= -1;
    }
    boii += sign*ans[n-1];
    // rep(i,0,n) cout<<ans[i]<<" ";
    // cout<<boii<<endl;
    reverse(arr,arr+n);
    i = 1;
    while(2*i-1 < n)
    {
        ans[2*i-1] = arr[n-i];
        i++;
    }
    k = n-i;
    j = 0;
    i = 2;
    while(i<n)
    {
        ans[i] = arr[j];
        j++;
        i += 2;
    }
    ans[0] = arr[j];
    ll boii1 = ans[0];
    sign = -1;
    rep(i,1,n-1)
    {
        boii1 += sign*2*ans[i];
        sign *= -1;
    }
    // rep(i,0,n) cout<<ans[i]<<" ";
    boii1 += sign*ans[n-1];
    // cout<<boii<<endl;
    cout<<max(boii,boii1)<<endl;


    
    
}



// Remove  debugs!!

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    #ifndef ONLINE_JUDGE
//        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
//    #endif
    int t=1;
//    cin>>t; int i=1;
    while(t--){
        //cout<<"Case #"<<i++<<": ";
        solve();
            //cout<<endl;    
      }
    return 0;
}