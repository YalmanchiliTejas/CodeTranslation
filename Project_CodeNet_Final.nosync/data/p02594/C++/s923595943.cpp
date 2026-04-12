#include <bits/stdc++.h>
using namespace std;

//Prashant Jangid...IIT KGP//
//Bubuuuuu//
/*int : 4B
long int : "4B in 32" and "8B in 64"
long long int : 8B */

/* 'a'=97 && 'z'=122
   'A'=65 && 'Z'=90
    
   char a='2';
   int num=a-48;
   && vice-versa...
/*       --------------------TEMPLATE----------------------        */

#define pie acos(-1)
#define int long long int
#define u unsigned 
#define ld long double
#define debug(a) cerr << #a << " = " << a << endl
#define pres(n) cout<<fixed<<setprecision(n)
#define MOD 1000000007
#define test_cases int T; cin>>T; while(T--)
#define loop(i,n) for(int i=0;i<n;i++)
#define rloop(i,n) for(int i=n-1;i>=0;i--)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define i1(x) int x;cin>>x;
#define i2(x,y) int x,y;cin>>x>>y;
#define i3(x,y,z) int x,y,z;cin>>x>>y>>z;
#define take(x,n) for(int i=0;i<n;i++) cin>>x[i];
#define print(a) for (auto x : a) cout << x << " "; cout << endl
#define initialise(n,k) memset(n,k,sizeof(n))
#define nextl cout<<endl
#define setbits(n) __builtin_popcount(n)
#define sz(x) (int)x.size()
#define INF 1e18
#define _INF -1e18
#define _y cout<<"YES\n";
#define _n cout<<"NO\n";

/*STL shorts*/

#define all(v) v.begin(), v.end()
#define mp(x,y) make_pair(x,y)
#define vi vector<int>
#define pii pair<int,int> 
#define stloop(itr,v) for(auto itr=v.begin();itr!=v.end();itr++)

//1...
template<class T>
void swap(T *xp, T *yp) 
{ 
    T temp = *xp;*xp = *yp;*yp = temp; 
} 
//2...
int gcd(int a,int b) 
{
    if(b==0)return a;
    else return gcd(b,a%b);
}
//3...
int nCr(int n,int k) //binomial cofficient//
{ 
    int res=1; 
    if(k>(n-k))
        k=n-k; 
    
    loop(i,k) 
    { 
        res*=(n - i); 
        res/=(i + 1); 
    } 
    return res;    
} 
//4...
int Ifact(int n) //factorial//
{
   int f=1,i;
   for(i=2;i<=n;i++)
   {
       f=f*i;
   }
   return f;
}
//5...
int pwr(int a,int b)  //"logb"//
{          
    int result=1;
    while(b>0) 
    {
        if(b&1)
          result=result*a;
        a=a*a;
        b>>=1;
    }
    return result;
}
//6...
int extended_gcd(int a,int b,int &x,int &y)
{
    if(b==0){
        x=1;y=0;return a;
    }
    int x1,y1;
    int d=extended_gcd(b,a%b,x1,y1);
    x=y1;
    y=(x1-y1*(a/b));
    return d;
}
//7
void sieve(bool *primes,int n, vector<int>* s)
{ 
    for(int i=0;i<=n;i++)
    {
        primes[i]=true;
    }
    primes[0]=primes[1]=false;
    for(int i=2;i*i<=n;i++)
    {
        if(primes[i]==true)
        {
            for(int p=i*i;p<=n;p+=i)
            {
                primes[p]=false;
            }
        }
    }
    for(int i=0;i<=n;i++)
    {
        if(primes[i])
        {
            s->push_back(i);
        }
    }
}
//8
int bintonum(string s)
{
    int i=0,res=0;
    for(int j=s.size()-1;j>=0;j--)
    {
        res+=(pwr(2,i)*(int)(s[j]));
        i++;
    }
    return res;
}
/*       --------------------CODE STARTS HERE----------------------        */


void solve()
{
    int n;
    cin>>n;
    if(n>=30)
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"No";
    }
    
    return;
}


int32_t main()
{

    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    solve();
    return 0;
}

// vector<bool> segmentedSieve(long long L, long long R) {
//     // generate all primes up to sqrt(R)
//     long long lim = sqrt(R);
//     vector<bool> mark(lim + 1, false);
//     vector<long long> primes;
//     for (long long i = 2; i <= lim; ++i) {
//         if (!mark[i]) {
//             primes.emplace_back(i);
//             for (long long j = i * i; j <= lim; j += i)
//                 mark[j] = true;
//         }
//     }

//     vector<bool> isPrime(R - L + 1, true);
//     for (long long i : primes)
//         for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
//             isPrime[j - L] = false;
//     if (L == 1)
//         isPrime[0] = false;
//     return isPrime;
// }



