#include<bits/stdc++.h>
using namespace std;
//#define ull unsigned  long  long
#define int long long int
#define lld long double
#define endl "\n"
#define S second
#define F first
#define pir      pair<int,int>
#define vtr      vector<int>
#define mpp      map<int,int>
#define pb       push_back
#define popb     pop_back()
#define mk       make_pair
#define stc      set<char>
#define st       set<int>
#define stk      stack<int>
#define ctn      continue
#define MOD      1000000007
#define fr(i,a,b)   for(int i=a;i<b;i++)
#define rfr(i,a,b)  for(int i=a-1;i>=b;i--)
#define must        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int gcd(int a, int b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
int lcm(int a, int b)
 {
    return (a*b)/gcd(a, b);
 }

int myfun(int x,int y)
{
    return x*y;
}
void primeFactors(int n)
{
    while (n%2 == 0)
    {
        cout<<2<<endl;
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        while (n%i == 0)
        {
            cout<<i<<endl;
            n = n/i;
        }
    }
    if (n > 2)
        cout<<n<<endl;
}

void fillPrefixSum(int arr[], int N, int prefixSum[])
{
    prefixSum[0] = arr[0];

    for (int i = 1; i < N; i++)
        prefixSum[i] = prefixSum[i-1] + arr[i];
}

int factorial(int n)
{
    return (n==1 || n==0) ? 1: n * factorial(n - 1);
}

int power(int x,  int y, int p){
    int res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
            y = y>>1;
            x = (x*x) % p;
    }
    return res;
}

int max(int a, int b) { return (a > b) ? a : b; }

// Returns the maximum value that
// can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n)
{

    // Base Case
    if (n == 0 || W == 0)
        return 0;

    // If weight of the nth item is more
    // than Knapsack capacity W, then
    // this item cannot be included
    // in the optimal solution
    if (wt[n] > W)
        return knapSack(W, wt, val, n - 1);

    // Return the maximum of two cases:
    // (1) nth item included
    // (2) not included
    else
        return max(
            val[n] + knapSack(W - wt[n],
                                    wt, val, n - 1),
            knapSack(W, wt, val, n - 1));
}



void solve()
{
     int n;
    cin>>n;
    int a[n];
    int ans=0;
    int pre[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(i!=0)pre[i]=pre[i-1]%MOD+a[i]%MOD;
        else pre[i]=a[i];
    }
    for(int i=n-1;i>=1;i--)
    {
        ans=ans%MOD+((a[i]%MOD)*(pre[i-1])%MOD)%MOD;
        //cout<<pre[i-1]<<" "<<ans<<endl;
    }
    cout<<ans%MOD<<endl;
    /*
    string s,t;
    cin>>s>>t;
    int mini=10000;
    for(int i=0;i<s.length();i++)
    {
        if(t[0]==s[i])
        {
            int p=1;
            for(int j=1;j<t.length();j++)
            {
                int q=i;
                q++;
                if(s[q]==t[j]) p++;
                else
                {
                    mini=min(mini,p);
                    break;
                }
            }
        }
    }
    if(mini==10000)
    {

    }
    else cout<<mini<<endl;
        */
}



signed main()
{
	must;
    int tt=1;
    //cin >> tt;
	while(tt--)solve();
	return 0;
}
