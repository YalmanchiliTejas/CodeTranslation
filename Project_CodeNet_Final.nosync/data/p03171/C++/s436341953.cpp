#include<bits/stdc++.h>
using namespace std;


/*###   FAST-IO  ###*/


#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);


/*###   DEBUGGGGGGG   ###*/


#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
#define testcases int testcases;cin>>testcases; while(testcases--)
#define queries int queries;cin>>queries; while(queries--)

/*###   TO PRINT   ###*/

#define pp1(a) cout << a << endl;
#define pp2(a, b) cout << a << " " << b << endl;
#define pp3(a, b, c) cout << a << " " << b << " " << c << endl;
#define pp4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << endl;
#define pp5(a, b, c, d, e) cout << a << " " << b << " " << c << " " << d << " " << e << endl;

/*###   SSSSSSS   ###*/

#define INF INT_MAX

#define endl "\n"
#define ll long long
#define int long long

ll mod = 1e9+7;

#define pb push_back
#define mp make_pair

#define pii pair<int,int>
#define msi map<string,int>
#define vi vector<int>
#define vpii vector<pair<int,int>>


#define ff first
#define ss second
#define sz size()

#define REP(i,a,b) for(int i=a;i<=b;i++)
#define REP1(i,a,b) for(int i=a;i<b;i++)
#define f0(n) for(ll i=0;i<n;i++)
#define f(n) for(ll i=1;i<=n;i++)
#define fn(a,n) for(ll a=0; a<n; a++)
#define flr(a,l,r) for(ll a=l; a<=r;a++)

#define sorta(a) sort(a.begin(), a.end());
#define sortd(a) sort(a.begin(), a.end(), greater<ll>());
#define sortdp(a) sort(a.begin(), a.end(), greater<pair<ll, ll>>());

#define blb(a, b) lower_bound(all(a), b) - a.begin();
#define bub(a, b) upper_bound(all(a), b) - a.begin();


#define stop return 0

/*###   SET-PRECISION   ###*/

void print_width(ll x) {
 
    std::cout << std::fixed;
    std::cout << std::setprecision(x);
}


/*###   COMPARATOR   ###*/


bool rev(int x,int y)
{
    return x>y;
}


/*###   PAIR_SORT_IN_DESCENDING_ORDER  ###*/


bool sortinrev(const pair<int,int> &a,  
               const pair<int,int> &b) 
{ 
       return (a.first > b.first); 
}


/*###   MODULO   ###*/


int modulo(int x,int N){
    return (x % N + N) %N;
}


/*###   MAX & MIN   ###*/


int max(int a,int b)
{
    if(a>=b)
        return a;
    else     
        return b;
}

int min(int a,int b)
{
    if(a<=b)
        return a;
    else     
        return b;
}


/*###   MOD-DIFFERENCE   ###*/


ll diff(ll a,ll b)
{
    if(a>=b)
        return a-b;
    else
        return b-a;
}


/*###   PAIR-SORTING   ###*/


void pairsort(int a[], int b[], ll n)
{
    pair<int, int> pairt[n];
    for (int i = 0; i < n; i++) 
    {
        pairt[i].first = a[i];
        pairt[i].second = b[i];
    }

    sort(pairt, pairt + n);

    for (int i = 0; i < n; i++) 
    {
        a[i] = pairt[i].first;
        b[i] = pairt[i].second;
    }
}


/*###   GCD && LCM   ###*/


ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b); 
}

ll lcm (ll a, ll b) {
    return a / gcd(a, b) * b;
}


/*###   PRIME OR NOT   ###*/


int isPrime(int n)
{
    if(n < 2)
        return 0;
    if(n < 4)
        return 1;
    if(n % 2 == 0 or n % 3 == 0)
        return 0;
    for(int i = 5; i*i <= n; i += 6)
        if(n % i == 0 or n % (i+2) == 0)
            return 0;
    return 1;
}


/*###   nCr   ###*/


long long C(int n, int r) {
    if(r > n - r) r = n - r;
    long long ans = 1;
    int i;
    for(i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}


/*###   MODULAR-EXPONENTIATION   ###*/


ll modexpo(ll x,ll p)
{
    ll res = 1;
    x = x%mod;
    while(p)
    {
        if(p%2)
            res = res * x;
        p >>= 1;
        x = x*x % mod;
        res %= mod;
    }
    return res;
}


/*###   POWER-FUNCTION   ###*/
 
ll power(ll x, ll y, ll p = mod)
{ 
    ll res = 1;      // Initialize result 
 
    x = x % p;  // Update x if it is more than or  
                // equal to p 
 
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res * x) % p; 
 
        // y must be even now 
        y = y >> 1; // y = y/2 
        x = (x * x) % p;   
    } 
    return res; 
}

/*###   STRING MULTIPLICATION   ###*/

string multiply(string num1, string num2) 
{ 
    int len1 = num1.size(); 
    int len2 = num2.size(); 
    if (len1 == 0 || len2 == 0) 
    return "0"; 
  
    // will keep the result number in vector 
    // in reverse order 
    vector<int> result(len1 + len2, 0); 
  
    // Below two indexes are used to find positions 
    // in result.  
    int i_n1 = 0;  
    int i_n2 = 0;  
      
    // Go from right to left in num1 
    for (int i=len1-1; i>=0; i--) 
    { 
        int carry = 0; 
        int n1 = num1[i] - '0'; 
  
        // To shift position to left after every 
        // multiplication of a digit in num2 
        i_n2 = 0;  
          
        // Go from right to left in num2              
        for (int j=len2-1; j>=0; j--) 
        { 
            // Take current digit of second number 
            int n2 = num2[j] - '0'; 
  
            // Multiply with current digit of first number 
            // and add result to previously stored result 
            // at current position.  
            int sum = n1*n2 + result[i_n1 + i_n2] + carry; 
  
            // Carry for next iteration 
            carry = sum/10; 
  
            // Store result 
            result[i_n1 + i_n2] = sum % 10; 
  
            i_n2++; 
        } 
  
        // store carry in next cell 
        if (carry > 0) 
            result[i_n1 + i_n2] += carry; 
  
        // To shift position to left after every 
        // multiplication of a digit in num1. 
        i_n1++; 
    } 
  
    // ignore '0's from the right 
    int i = result.size() - 1; 
    while (i>=0 && result[i] == 0) 
    i--; 
  
    // If all were '0's - means either both or 
    // one of num1 or num2 were '0' 
    if (i == -1) 
    return "0"; 
  
    // generate the result string 
    string s = ""; 
      
    while (i >= 0) 
        s += std::to_string(result[i--]); 
  
    return s; 
} 



/*###   STRING TO INT   ###*/

int sti(string s) {
 
    int ans = 0;
    int p = 1;
 
    for (int i = s.size() - 1; i >= 0; i--) {
        ans = (ans + ((ll)(s[i] - '0') * p) % mod) % mod;
        p = (p * 10) % mod;
    }
    return ans;
 
}

/*###   TIMER   ###*/


void time() {
    #ifndef ONLINE_JUDGE
    cout << "\nTime: " << 1.0 * clock() / CLOCKS_PER_SEC << "s\n";
    #endif
}

                                    /*************************** END OF TEMPLATE ****************************/


const int N=1e6+5;
const int despacito=1e9+7;


const int nax=3005;
int dp[nax][nax];



int32_t main()
{
    

    IOS

    int n;
    cin>>n;

    vi a(n);
    for(int& x:a){
    	cin>>x;
    }
    //dp[0][n-1]
    for(int L=n-1;L>=0;L--){
    	for(int R=L;R<n;R++){
    		if(L==R)
    			dp[L][R]=a[L];
    		else{
    			dp[L][R]=max(a[L]-dp[L+1][R],a[R]-dp[L][R-1]);
    		}
    	}
    }
    
    cout<<dp[0][n-1]<<endl;



    






    
    //time();
    stop;
}