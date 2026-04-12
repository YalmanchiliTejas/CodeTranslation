#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ll long long
#define ull unsigned long long int
#define db double
#define fi first
#define se second
#define pb push_back
#define vec vector<ll>
#define pr pair<ll,ll>
#define pq priority_queue<ll,vector<ll> >
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define repn(i,n) for(ll i=0;i<n;i++)
#define all(a)      (a).begin(),(a).end()
#define sz(x)       (ll)x.size()
#define rep(i,a,b)    for(ll i=a;i<b;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
typedef priority_queue<ll,vector<ll>,greater<ll>> pqlg;
#define GS(s)   string s; getline(cin,s);
#define lll __int128_t
#define endl "\n"

struct compare_queue
{
    bool operator()(const ll& a, const ll& b)
    {
        return a>b;
    }
};

// ll gcd(ll u,ll v)
// {
// 	if(v==0)
// 	return u;
	
// 	else
// 	return gcd(v,u%v);
// }

    // ll power(ll x,ll y){
    //     ll i;
    //     ll ans=1;
    //     for(i=0;i<y;i++){
    //         ans=ans*x;
    //     }
    //     return ans;
    // }

// // // #define MAX 1000000
// int primes[100009],cnt=0;
// // vector<int> factors[1000009];
// char str[1000009];
// void pre()
// {
//     // calcualting primes
//     int n=1000000;
//     for(int i=2; i*i<=n; i++)
//         if(str[i]==0)
//             for(int j=i; j*i<=n; j++)
//                 str[i*j]=1;
//     for(int i=2; i<=n; i++)
//         if(str[i]==0)primes[cnt]=i,cnt++;
// }


// A O(log n) function returning primefactorization 
// by dividing by smallest prime factor at every step 
// vector<ll> getFactorization(ll x) 
// { 
//     vector<ll> ret; 
//     while (x != 1) 
//     { 
//         ret.push_back(spf[x]); 
//         x = x / spf[x]; 
//     } 
//     return ret; 
// } 

// C:\Users\A\AppData\Local\Packages\CanonicalGroupLimited.UbuntuonWindows_79rhkp1fndgsc\LocalState\rootfs\home\lambda

ll power(ll x,ll y,ll p) 
{ 
	ll res = 1;	

	x = x % p; 

	if (x == 0) return 0;

	while (y > 0) 
	{ 
		
		if (y & 1) 
			res = (res*x) % p; 

		y = y>>1; 
		x = (x*x) % p; 
	} 
	return res; 
} 

// struct node{
// int val;
// node* left;
// node* right;
// };

// node* getNode(int k){
//     node* temp =new node;
//     temp->left=NULL;
//     temp->right=NULL;
//     temp->val=k;
// }



void Function(){
ll n,m,s=0;
m=pow(10,9)+7;
cin >> n;
vec a(n);
repn(i,n){
cin >> a[i];
s=((s%m)+ (a[i]%m))%m;
}

ll ans=0;

repn(i,n){
    s=((s%m)-a[i] + m)%m;
    ans=((ans%m) + (((a[i]%m)*(s%m))%m))%m;
}

cout << ans << endl;

}

int main(){ 
fast;
ll t=1,i=0,j=0,k=0,h,n;
// pre();
// cin >> t;
for(h=1;h<=t;h++){
Function();
}
return 0;
}