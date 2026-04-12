/*
--------DO NOT COPY I REQUEST YOU PLEASE--------
 
AUTHOR : Chandan Agrawal
College : Poornima College of Engg. jaipur, Raj
Mail : chandanagrawal23@gmail.com
 
 
  ___  _   _    __    _  _  ____    __    _  _
 / __)( )_( )  /__\  ( \( )(  _ \  /__\  ( \( )
( (__  ) _ (  /(__)\  )  (  )(_) )/(__)\  )  (
 \___)(_) (_)(__)(__)(_)\_)(____/(__)(__)(_)\_)
 
/*
 
A ^ (B ^ C) % M = (A ^ y ) %  M
 
where y = (B ^ C)%(M-1)

//
                              \
a^(m-1) â‰¡ 1 (mod m)
 
If we multiply both sides with a-1, we get

a^(-1) â‰¡ a^(m-2)(mod m)
 
*/
 
#include<bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#include<cstdio>
#define MAX 7000005
#include<stdio.h>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstring>
 
#include<cstdlib>
#include<cassert>
#include<unordered_map>
#define ll long long
#define ld long double
#define lli long long int
#define pb push_back
#define INF 1000000000
#define mod 1000000007
#define MOD 1000000007
//#define mp make_pair
#define loop(i,n) for (lli i = 0; i < n; i++)
#define loopitr(xt,vec) for (auto xt : vec)
#define FOR(i,a,b) for (lli i = a; i < b; i+=1)
#define loop_rev(i,n) for (lli i = n-1; i >= 0; i--)
#define FOR_REV(i,a,b) for (lli i = a; i >= b; i--)
#define all(v) v.begin(),v.end()
#define sz(x) int(x.size())
#define pii pair<int,int>
#define F first
#define S second

#define mii map<lli,lli>
#define vi vector<lli>
#define seti set<lli>

#define itr :: iterator it
#define WL(t) while(t --)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) (a/gcd(a,b))*b
#define abs(x) ((x < 0)?-(x):x)
 
#define print(x) printf("%lli\n",x);
#define print2(x,y) printf("%lli %lli\n",x,y);
#define print3(x,y,z) printf("%lli %lli %lli\n",x,y,z);
 
#define scan(x) scanf("%lld",&x);
#define scan2(x,y) scanf("%lld %lld",&x,&y);
#define scan3(x,y,z) scanf("%lld %lld %lld",&x,&y,&z);
 
#define scanarr(a,n) for(lli i=0;i<n;i++)    cin>>a[i];
#define scanvector(a,n) for(lli i=0;i<n;i++){ lli x ; cin>>x; a.push_back(x);}
 
#define printarr(a,n) for(lli i=0;i<n;i++)   printf("%lli ",a[i]); printf("\n");
#define printvector(vec) for(auto xt : vec) cout<<xt<<" ";    cout<<"\n";
#define printset(st) for(auto xt : st) cout<<xt<<" ";    cout<<"\n";
 
#define FD(N) fixed<<setprecision(N)
 
#define endl '\n'
 
#define deb(x) cout<<#x<<" "<<x<<endl;
 
 
lli find_mod(string s){
lli i,x=0;
for(i=0;i<s.length();i++)
    x=(x*10+s[i]-'0')%MOD;
return x;
}
 
     
lli prime[MAX+1];
     
void sieve1(){ //prime or not
    for(int i=0;i<=MAX;i++) prime[i]=1;
    prime[0]=prime[1]=0;
    for(lli i=4;i<=MAX;i+=2) prime[i]=0;
    for (int p=3; p*p<=MAX; p+=2){
        if (prime[p] == 1)
            for (int i=p*2; i<=MAX; i += p){
                prime[i] = 0;
}}}
 
int min_prime_div_of_n[MAX+1];
 
void sieve2(){ //smallest prime factor which divide a no.
memset(min_prime_div_of_n, 0, sizeof(min_prime_div_of_n));
	min_prime_div_of_n[0] = min_prime_div_of_n[1] = 1;
	for (int i = 2; i * i <= MAX; i++) {
		if (min_prime_div_of_n[i] == 0) {
			for (int j = i * 2; j < MAX; j += i) {
				if (min_prime_div_of_n[j] == 0){
				min_prime_div_of_n[j] = i;
					//cout<<min_prime_div_of_n[i]<<" ";}
			}
		}
	}
}
	for (int i = 2; i <=MAX; i++)
		if (min_prime_div_of_n[i] == 0)
			min_prime_div_of_n[i] = i;
		// If the number is prime then it's // smallest prime factor is the number // itself
}
 
int max_prime_div_of_n[MAX+1];
 
void sieve3(){ //maximum prime factor which divide a no.
    sieve1();
    memset(max_prime_div_of_n, 0, sizeof(max_prime_div_of_n));   //0 stands for is_prime
	max_prime_div_of_n[0] = max_prime_div_of_n[1] = 1;
	for (int i = 2; i * i <= MAX; i++) {
		if (max_prime_div_of_n[i] == 0) {
   			for (int j = i * 2; j < MAX; j += i) {
   				if (max_prime_div_of_n[j] == 0 || ((j%i)==0 && prime[i]==1) ){
   					max_prime_div_of_n[j] = i;
                       }
   			}
   		}
   	}
   	for (int i = 2; i <=100; i++)
   	    	// If the number is prime then it's largest prime factor is the number  itself
   		if (max_prime_div_of_n[i] == 0) max_prime_div_of_n[i] = i;
   			//cout<<max_prime_div_of_n[i]<<" ";
    
   }
    
lli sum_prime_fac[1000001];
    
void sieve4(){ //prime or not
    sum_prime_fac[1000001] = {0};
    for(lli i=2;i<=1000000;i++){
            if(!sum_prime_fac[i]){
                    for(lli j=i;j<=1000000;j+=i)
                        sum_prime_fac[j]+=i;
            }
    }
}
     
     
     
bool is_even(lli n){ return(!(n&2));}
     
bool is_odd(lli n){ return(n&2);}
     
/*bool isPower(lli n)
{
	// Find Log n in different bases
	// and check if the value is an
	// integer
	float f=log(n)/log(2);
	if (((f - (int)f) == 0.0) && prime[int(f)]==1)
			return true;
	for (lli x=3; x<=sqrt(n); x+=2) {
		f = log(n) / log(x);
		if (((f - (int)f) == 0.0) && prime[int(f)]==1 && prime[x]==1 )
			return true;
	}
	return false;
}
*/
// memset(array_name , initialized value , sizeof(data_type_of_array))
lli sum(lli n){
    lli sum=0;
while(n){
    sum+=n%10;
    n/=10;
}
return sum;
}
     
bool isPrime(lli n){
if(n<=1) return false;
if(n<=3) return true;
if(n==5) return true;
if((n%2==0)||(n%3==0) || (n%5==0)) return false;
for(lli i=5;i*i<=n;i+=6)
    if((n%i==0)||(n%(i+2)==0))
        return false;
return true;
}
     
lli reversenum(lli x){
lli num=0;
while(x>0){
    num=num*10+x%10;
    x=x/10;
    }
return num;
    }
     
bool ispalindrome(string s){
string q = s;
reverse(q.begin(),q.end());
return(s==q);
}
 
bool isvowel(char x){    return(x=='a' || x== 'e' ||x=='i' || x== 'o' || x=='u' );    }
     
/*inline void fastRead(lli &x) {
	    register int c = getchar_unlocked();
	    x = 0;
	    int neg = 0;
	    for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());
	    if(c=='-'){
    	    	neg = 1;
	        c = getchar_unlocked();}
	    for(; c>47 && c<58 ; c = getchar_unlocked()){x = (x<<1) + (x<<3) + c - 48;}
    if(neg){ x = -x;}
}*/
     
lli mceil(lli a,lli b){
    if(a%b==0) return(a/b);
    else return(a/b  +1);
}
lli mfloor(lli a,lli b){
    if(a%b==0) return(a/b);
    else return(a/b  -1);
}
lli sumarr(lli a[],lli n){
    lli sum=0;
    loop(i,n) sum+=a[i];
    return sum;
}
     
ll modmul(ll a, ll b) {
	return ((a%mod) * (b%mod)) % mod;
}
     
ll modadd(ll a , ll b){
    return((a%mod)+(b%mod)+mod)%mod;
}
 
ll modsub(ll a , ll b){
    return((a%mod) - (b%mod) + mod)%mod;
}
 
lli fastexpo(lli a,lli b){
    a = a%mod;
    lli ans=1;
    while(b){
        if(b%2)
            ans=(ans*1ll*a)%mod;
        a=(a*1ll*a)%mod;
        b=b/2;
        }
    return ans;
 }
     
lli findmax(lli a[],lli x,lli y){
     
    lli maxi=-1;
    for(lli i=x;i<=y;i++)
        maxi = max(maxi , a[i]);
    return maxi;
}
     
     
lli phi[MAX];
void euler_phi(){ //euler totient function
loop(i,MAX-1)
    phi[i+1] = i+1;
for (lli p=2; p<MAX; p++){
    if (phi[p] == p){
        phi[p] = p-1;

        for (lli i = 2*p; i<MAX; i += p)
               phi[i] = (phi[i]/p) * (p-1);
 
        }
    }
}

lli myphi(lli n) 
{ 
    lli result = n;
    for (lli p = 2; p * p <= n; ++p) { 
        if (n % p == 0) { 
            while (n % p == 0) 
                n /= p; 
            result -= result / p; 
        } 
    } 
    if (n > 1) 
        result -= result / n; 
    return result; 
} 
     
     
void prime_factorise(lli n , map<lli,lli> &mp){
 
    while(n%2==0){
        mp[2]++;
        n/=2;
    }
    for(lli i=3;i*i<=n;i+=2){
        while(n%i==0){
            mp[i]++;
            n/=i;
        }
    }
 
    if(n>1) mp[n]++;
 
 }
     
// Returns largest power of p that divides n!
lli largestPower(lli n,lli p){
 
    lli total = 0;
    // Calculate x = n/p + n/(p^2) + n/(p^3) + ....
    while (n)
    {
        n /= p;
        total += n;
    }
    return total;
}
 
lli fact[100001];
void facto(){
    fact[0] = 1;
    for(lli i=1;i<=100000;i++)
        fact[i]  = modmul(fact[i-1],i);
}
void finddiv(lli n,seti &st){
    for(lli i=1;i*i<=n;i++){
        if(n%i==0){
            st.insert(i);
            st.insert(n/i);
        }
    }
}
     
lli findncr(lli n,lli r){
    if(n<r)
        return 0;
    else{
        r = min(r,n-r);
        lli a=1,b=1;
    	    for(lli i=0;i<r;i++) {
    	        a = (a*(n-i))%mod;
    	        b = (b*(i+1))%mod;
    	    }
    	    a = modmul(a,fastexpo(b,mod-2));
    	    return a;
    }
}

bool func(lli a[],lli b[],lli n){
    set<lli>st;
    loop(i,n){
        if(st.find(a[i]+b[i])==st.end())
            st.insert(a[i]+b[i]);
        else
            return true;
    }
    return false;
}

void rotate(lli a[],lli n){
    lli val=a[0];
    for(lli i=0;i<n-1;i++)
        a[i] = a[i+1];
    a[n-1] = val;
}

void chandan(){
    return;
}

int main(){
fastIO
lli t=1;
//lli op=1;
//cin>>t;
while(t--) {
    string s;
    cin>>s;
    if(s=="AAA" || s=="BBB")
        cout<<"No";
    else
        cout<<"Yes";
    
    }
return 0;
}
