#include<iostream> 
#include<vector> 
#include<algorithm> 
#include<iomanip> 
#include<stack> 
#include<unordered_map>
#include<queue> 
#include<map>
#include<climits>
#include<set> 
#include<string> 
//#include<bits/stdc++.h> 
using namespace std; 
#define lld long long int 
#define eb emplace_back
//to insert pair use eb
#define mp make_pair
#define fi first
#define se second
#define pb push_back

#define X 1000000007
#define Y 998244353
#define E4 10000
#define E5 100000
#define E6 1000000
#define inf 1001001001
#define longinf 2001001001001001001
#define pi 3.1415926535

# define rec2(i,a,b) for(lld i=a;i<b;i++) 
#define rec(i,n) for(lld i=0;i<n;i++)
#define rev(i,a,b) for(lld i=b-1;i>=a;i--)
#define all(v) (v).begin(), (v).end()
#define large(v)  *max_element(all(v))
#define small(v)  *min_element(all(v)) 
#define v vector
const double EPS = 1e-6;

void google(int i)
{  cout<<"Case #"<<i<<":"<<endl; }

//prime sieve if needed 
//prime factors of number
lld prime[E6+1]; 
void sieve(lld n) 
{ rec(i,n+1) 
    prime[i]=1; 
   for(lld i=2;i*i<=n;i++) 
     { if(prime[i]!=1) 
          continue; 
         for(lld j=i*i;j<=n;j=j+i) 
          if(prime[i]==1)
           prime[j]=i; 
      }
}

lld gcd(lld a,lld b)
{
    if(a==0)
     return b; 
    return gcd(b%a,a); 
}

//fermat a^(m-2)%mod
lld binarymul(lld a,lld n,lld m)
{  lld res=1; 
 while(n) 
  { if(n%2) 
      { res=(res*a)%m; 
         n--; 
      } 
     a=(a*a)%m; 
     n/=2; 
  }
  return res; 
}
void contest(); 
int main()
{
   ios_base::sync_with_stdio(false); 
   cin.tie(0);
     #ifdef PUNEET_GOEL
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif
   //sieve(E6); 
    lld t; 
//    cin>>t; 
t=1; 
    rec(i,t) 
    {
     //google(i+1); 
      contest(); 
    }
	return 0;
}

void contest()
{ 
  lld n; 
  cin>>n; 
  if(n>=30) 
   cout<<"Yes"; 
   else 
   cout<<"No"; 
   cout<<endl; 
}