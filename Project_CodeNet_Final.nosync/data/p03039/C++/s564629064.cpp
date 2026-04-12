#include<bits/stdc++.h>
#include <queue> 
#include<map>
#define ll long long
#define ull unsigned long long 
#define ld long double
#define all(ar) ar.begin(), ar.end()
#define sot(bello) bello.begin(),bello.end()
#define bitc  __builtin_popcountl
#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (int i = n - 1; i >= 0; i--)
#define fill(ar,val) memset(ar, val, sizeof(ar))
#define fill0(ar) fill((ar), 0)
#define MAXN   100010 
#define MOD 1000000007
#define debug(x) cout<<#x<<": "<<x<<endl
#define dbug(x) cout<<#x<<": "<<x<<" "
#define fi first
#define se second
#define arr1d(a,n) cout << #a << " : "; fr(_,1,n) cout << a[_] << ' '; cout << endl;
#define arr1d0(a,n) cout << #a << " : "; rep(_,n) cout << a[_] << ' '; cout << endl;
#define arr2d(a,n,m) cout << #a << " :" << endl; fr(_,1,n) {fr(__,1,m) cout << a[_][__] << ' '; cout << endl;}
#define arr2d0(a,n,m) cout << #a << " :" << endl; rep(_,n) {rep(__,m) cout << a[_][__] << ' '; cout << endl;}

# define INF LLONG_MAX
const int dx[]={0,0,-1,1},dy[]={-1,1,0,0};



using namespace std;
//gcd
ll Gcd(ll a,ll b){
	if(a%b==0) return b;
	return Gcd(b,a%b);
}
//max
ll Max(ll a,ll b){
	if(a>b)
	return a;
	return b;
}
//min
ll Min(ll a,ll b){
	if(a<b)
	return a;
	return b;
}


void printvector(std::vector<ll> v){  for (int i = 0; i < v.size(); ++i){cout<<v[i]<<" ";}cout<<""<<endl;}
void printarray(ll a[],ll n){for (ll i = 0; i < n; ++i){cout<<a[i]<<" ";}cout<<""<<endl;}

ll findlcm(vector<ll> arr, ll n) 
{ 
    // Initialize result 
    ll ans = arr[0]; 
  
    // ans contains LCM of arr[0], ..arr[i] 
    // after i'th iteration, 
    for (int i = 1; i < n; i++) 
        ans = (((arr[i] * ans)) / 
                (Gcd(arr[i], ans))); 
  
    return ans; 
} 


ll gcdExtended(ll a, ll b, ll *x, ll *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
 
    ll x1, y1; 
    ll gcd = gcdExtended(b%a, a, &x1, &y1);
 
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}




   
 
 ll power(ll x, ll y, ll p) 
{ 
    ll res = 1;      
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






ll modInverse(ll a, ll m)
{
    ll x, y;
    ll g = gcdExtended(a, m, &x, &y);
    if (g != 1)
        return -1 ;
    else
    {
        
        ll res = (x%m + m) % m;
        return res;
    }
}





vector<ll> primeFactors(ll n)
{    
    vector<ll> v;
	while (n%2 == 0)
	{
		v.push_back(2);
		n = n/2;
	}
	for (int i = 3; i <= sqrt(n); i = i+2)
	{
		while (n%i == 0)
		{
			v.push_back(i);
			n = n/i;
		}
	}

	if (n > 2)
		v.push_back(n);
		return v;
}


ll lowerbound(ll k,vector<ll> v){
  //lowerbound to be used when first index such that
  // ar[index]>=k is needed

  ll l=0;
  ll size=v.size();
  ll r=size-1;
  ll mid;
  while (l<=r)
  {
      mid=(l+r)/2;
      if(v[mid]<k) l=mid+1;
      else{
          r=mid-1;
      }
  }
  return l;

}

ll upperbound(ll k,vector<ll> v){
  //lowerbound to be used when first index such that
  // ar[index]>k is needed
  ll l=0;
  ll size=v.size();
  ll r=size-1;
  ll mid;
  while (l<=r)
  {
      mid=(l+r)/2;
      if(v[mid]>k) r=mid-1;
      else{
          l=mid+1;
      }
  }
  return l;

}


ll C[2001][2000]; 

void binomialCoeff(ll n, ll k) 
{ 
   
    ll i, j; 
  
    // Caculate value of Binomial Coefficient in bottom up manner 
    for (i = 0; i <= n; i++) 
    { 
        for (j = 0; j <= k; j++) 
        { 
            // Base Cases 
            if (j == 0 || j == i) 
                C[i][j] = 1; 
  
            // Calculate value using previosly stored values 
            else
                C[i][j] = (C[i-1][j-1]%MOD + C[i-1][j]%MOD)%MOD; 
        } 
    } 
  
    //return C[n][k]; 
} 


//Manachar's Algorithm
string convertToNewString(const string &s) {
    string newString = "@";

    for (ll i = 0; i < s.size(); i++) {
        newString += "#" + s.substr(i, 1);
    }

    newString += "#$";
    return newString;
}

string longestPalindromeSubstring(const string &s) {
    string Q = convertToNewString(s);
    ll c = 0, r = 0;          
    ll P[Q.size()+4]={};
    for (ll i = 1; i < Q.size() - 1; i++) {
        ll iMirror = c - (i - c);
         
        if(r > i) {
            P[i] = min(r - i, P[iMirror]);
        }
        while (Q[i + 1 + P[i]] == Q[i - 1 - P[i]]){
            P[i]++;
        }

        if (i + P[i] > r) {
            c = i;            
            r = i + P[i];
        }
    }
    int maxPalindrome = 0;
    int centerIndex = 0;

    for (int i = 1; i < Q.size() - 1; i++) {

        if (P[i] > maxPalindrome) {
            maxPalindrome = P[i];
            centerIndex = i;
        }
    }

    cout << maxPalindrome << "\n";
    return s.substr( (centerIndex - 1 - maxPalindrome) / 2, maxPalindrome);
}





  
ll spf[MAXN]; 
  
void sieve() 
{ 
    spf[1] = 1; 
    for (int i=2; i<MAXN; i++) 
      spf[i] = i; 
   for (int i=4; i<MAXN; i+=2) 
        spf[i] = 2; 
  
    for (int i=3; i*i<MAXN; i++) 
    { 
        if (spf[i] == i) 
        { 
           for (int j=i*i; j<MAXN; j+=i) 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
} 




ll binarySearch(ll arr[], ll l, ll r, ll x)
{
   if (r >= l)
   {
        ll mid = l + (r - l)/2;
        if (arr[mid] == x)  
            return mid;
 
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid-1, x);
 
        return binarySearch(arr, mid+1, r, x);
   }
 
   return -1;
}


//Segment Tree Implementation

          const ll N = 100000; 
 
ll n; 
 
           ll tree[2 * N];

void build( ll arr[]) 
{ 
    for (ll i=0; i<n; i++)    
        { tree[n+i] = arr[i];
	       
	     }
     
    for (ll i = n - 1; i > 0; --i)     
        {tree[i] = tree[i<<1] + tree[i<<1 | 1];    
              /* cout<<"i<<1  is "<<(i<<1)<<endl;
               cout<<"i<<1 | 1  is "<<(i<<1 | 1)<<endl;*/
	     }
}
 
void updateTreeNode(ll p, ll value) 
{ 
    tree[p+n] = value;
    p = p+n;
     
    for (ll i=p; i > 1; i >>= 1)
        {tree[i>>1] = tree[i] + tree[i^1];
	       }
}
 
ll query(ll l, ll r) 
{ 
    ll res = 0;
     
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l&1) 
           {    
			   res += tree[l++];
               
               }    
        if (r&1) 
             {   res += tree[--r];
				 
            }
    }
     
    return res;
}


//Dijkstra's Algorithm

vector<ll> shortPath( vector<pair<ll,ll> > v[],ll src,ll V=0) 
{ 
     set< pair<ll,ll> > setds; 
  
    ll sizee=V;
    ll IN=INF;
    vector<ll> dist(sizee, IN); 
  
    setds.insert(make_pair(0, src)); 
    dist[src] = 0; 
  
    while (!setds.empty()) 
    { 
        pair<ll, ll> tmp = *(setds.begin()); 
        setds.erase(setds.begin()); 
  
        ll u = tmp.second; 
  
        vector< pair<ll, ll> >::iterator i; 
        for (i = v[u].begin(); i != v[u].end(); ++i) 
        { 
            ll v = (*i).first; 
            ll weight = (*i).second; 
      if (dist[v] > dist[u] + weight) 
            { 
                if (dist[v] != INF) 
                    setds.erase(setds.find(make_pair(dist[v], v))); 
  
                dist[v] = dist[u] + weight; 
                setds.insert(make_pair(dist[v], v)); 
            } 
        } 
    }
    return dist;
} 



ll root(ll a[],ll r)
{
     if(a[r]==r)
     {
       return r;
     }
     else
     {
       ll x=root(a,a[r]);
       a[r]=x;
       return x;
     }

} 
 
void unio(ll a[],ll  size[],ll  x,ll  y){
  x=root(a,x);
  y=root(a,y);
  if(x==y){return;}
  if(size[x]>=size[y])
  {
       a[y]=x;
       size[x]+=size[y];
  }
  else
  {
      a[x]=y;
      size[y]+=size[x];
  }
 
}


// Sieve Implementation
/* 
for (ll i=2;i<=100005;i++)
        if (p[i]==0)
        for (ll j=2*i;j<=100005;j+=i) p[j]=1; */


// Dfs search

void dfs(std::vector<ll> v[],ll s,bool visited[])
{
	visited[s]=true;
  for (ll i = 0; i < v[s].size(); ++i)
  {
  	if(!visited[v[s][i]] )
  	{ 
  		dfs(v,v[s][i],visited);

  	}

  }


}





//do not use n , N , C


// Using iterators in C++ 
//set<ll>:: iterator it;

    

ll f[2000005];
ll inv[2000005];
void pre()
{
    f[0]=1;
    for(ll i=1;i<=2000004;i++)
        f[i]=(f[i-1]*i)%MOD;
    inv[2000004]=power(f[2000004],MOD-2,MOD);
    for(ll i=2000003;i>=0;i--)
        inv[i]=((i+1)*inv[i+1])%MOD;
}
ll ncr(ll n,ll r)
{
    return (((f[n]*inv[n-r])%MOD)*inv[r])%MOD;
}


int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
ll n,m,k;
    cin>>n>>m>>k;
    pre();
    ll co=ncr(n*m-2,k-2);
    ll zz=1;
    // debug(co);
    co=(co*zz)%MOD;
    ll ro=(n*co)%MOD;
    ro=ro*n%MOD;
    co=(m*co)%MOD;
    co=co*m%MOD;
    ll c1=m*(m-1)/2;
    ll z1=m-1;
    ll ans1=0;
    // debug(ro);
    // debug(co);
    for(ll i=1;i<=m;i++)
    {
        ans1=(ans1+c1)%MOD;
        c1-=z1;
        z1--;
    }
    // debug(ans1);
    c1=n*(n-1)/2;
    z1=n-1;
    ll ans2=0;
    for(ll i=1;i<=n;i++)
    {
        ans2=(ans2+c1)%MOD;
        c1-=z1;
        z1--;
    }
    ans1=ro*ans1%MOD;
    ans2=co*ans2%MOD;
    cout<<(ans1+ans2)%MOD;



 //return 0;
}







