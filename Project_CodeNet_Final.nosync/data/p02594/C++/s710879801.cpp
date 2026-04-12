#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define vb vector<bool>
#define pii pair<int,int>
#define mii map<int,int>
#define all(c)  c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define inf (long long) 1e18
#define F first
#define S second
#define SZ(x) ((int)(x).size())
//#define rep(i,n)  for(int i=0;i<n;i++)
//#define repd(i,n) for(int i=n-1;i>=0;i--)
//#define rep1(i,n) for(int i=1;i<=n;i++)
const int N = 1e9 + 7;
 
int pow(int x, int y) { int res = 1; while (y > 0) { if (y & 1) res = ((res) * (x)); res %= N; y = y >> 1; x = ((x) * (x)); } return res; }
int powm(int x, int y, int p)  {  int res = 1; x = x % p; while (y > 0) {if (y & 1) res = (res * x) % p; y = y >> 1; x = (x * x) % p;}   return res; }
 
 int min2(int x,int y)
 {
     if(x<=y)
     return x;
     else 
     return y;
 }
void compute()
{
    int n;
    cin>>n;
    if(n>=30)
    {
        cout<<"Yes\n";
    }
    else
    {
        cout<<"No\n";
    }
    

 
} 
 
int main()
{
#ifdef debug
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("log.txt", "w", stderr);
#endif
 //   int t;
   // scanf("%d", &t);
    //while (t--)
    //{
        compute();
   // } //end while
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
} //end main*