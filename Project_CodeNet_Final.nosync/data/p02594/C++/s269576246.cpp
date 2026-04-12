//*******Abhijit Burman***********//
//Jalpaiguri Government Engineering College//

// Taken From Striver_79
// Never open a ranklist untill and unless you are done with solving problems, wastes 3/4 minuts 
// Donot treat CP as a placement thing, love it and enjoy it, you will succeed for sure. 


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define ff first
#define ss second
#define mk make_pair
#define MAXX (1000000000000000000+7)
#define mod 1000000007
#define fio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
ll dx1[] = {1, 1, 0, -1, -1, -1, 0, 1};
ll dy1[] = {0, 1, 1, 1, 0, -1, -1, -1};

ll dx2[] = {1, 0, -1, 0};
ll dy2[] = {0, 1, 0, -1};

ll mul(ll a, ll b, ll p = mod) {return ((a % p) * (b % p)) % p;}
ll add(ll a, ll b, ll p = mod) {return (a % p + b % p) % p;}
ll power(ll x,ll y,ll p = mod) 
{ 
    ll res = 1;
    x = x % p;
    while (y > 0) 
    {
        if (y & 1) 
            res = (res*x) % p;
        y = y>>1; // y = y/2 
        x = (x*x) % p; 
    } 
    return res; 
} 
ll modInverse(ll n, ll p = mod)
{
    return power(n, p - 2, p);
}
ll ncrMod(ll n, ll r, ll p = mod)
{
    if (r == 0)
        return 1;
    ll fac[n + 1];
    fac[0] = 1;
    for (ll i = 1 ; i <= n; i++)
        fac[i] = fac[i - 1] * i % p;
    return (fac[n] * modInverse(fac[r], p) % p *
            modInverse(fac[n - r], p) % p) % p;
}
// a+b=xor(a,b)+2*(a&b)//

bool isPrime(ll n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}


void solve()
{
    ll n;
    cin>>n;
    
    cout<<(n>=30?"Yes":"No")<<endl;
}


int main()
{
	fio;
// 	#ifndef ONLINE_JUDGE
//     // for getting input from input.txt
//     freopen("input.txt", "r", stdin);
//     // for writing output to output.txt
//     freopen("output.txt", "w", stdout);
// 	#endif
 

	ll t=1;
// 	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}