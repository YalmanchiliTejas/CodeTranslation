#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define lli long long int
#define ulli unsigned long long int
#define ld long double
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define loop(i,a,b) for(lli i=a;i<b;i++)
#define initialize(array,size,value) for(lli i=0;i<size;i++) array[i]=value
#define couta(array,size) for(lli i=0;i<size;i++) cout<<array[i]<<" "
#define vl vector<lli>
#define vp vector< pair <lli,lli> >
#define sl set<lli>
#define msp multiset < pair < long long , long long > > S;
#define pll pair<lli, lli>
#define mll map<lli, lli>            //for( map<lli, lli>::iterator i=temp.begin();i!=temp.end();i++)cout<<i->fi<<" "<<i->se<<endl;
#define mvl map<lli, vl>
#define umll unordered_map<lli, lli>
#define vt vector<pair<lli, pll >  >
#define vf vector<pair<pll,pll > >
#define qu queue<lli>
#define pq priority_queue<lli>
#define dq deque <lli>
#define ptr vector<lli>::iterator
#define bs(array,x) binary_search(array.begin(),array.end(),x) // also valid for set and multiset
#define lb(array,x) lower_bound(array.begin(),array.end(),x)
#define ub(array,x) upper_bound(array.begin(),array.end(),x)
#define nobw(array,i,j) upper_bound(array.begin(), array.end(), j)-lower_bound(array.begin(), array.end(), i) //number of numbers between i & j
#define vc clear()
#define endl '\n'
#define sp system("pause");
#define INF 9223372036854775807
#define MINF -9223372036854775808
typedef tree<pll,null_type,less<pll>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;
//string binary = bitset<32>(n).to_string(); 
lli mod=1000000007;
lli power(lli x, lli y,lli p) 
{ 
    lli res = 1;      // Initialize result 
    x = x % p;  // Update x if it is more than or 
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % p; 
        y = y>>1; // y = y/2 
        x = (x*x) % p; 
    } 
    return res; 
} 
lli modInverse(lli n, lli p) 
{ 
    return power(n, p-2, p); 
} 
lli nCrModPFermat(lli n, lli r,lli p) 
{ 
   if (r==0) 
      return 1; 
    lli fac[n+1]; 
    fac[0] = 1; 
    for (lli i=1 ; i<=n; i++) 
        fac[i] = fac[i-1]*i%p; 
    return (fac[n]* modInverse(fac[r], p) % p * 
            modInverse(fac[n-r], p) % p) % p; 
} 
int main()
{

 	ios::sync_with_stdio(0);
    cin.tie(0);
    lli n,m,k;
    cin>>n>>m>>k;
    lli sum=0;
    for(lli i=0;i<=n-2;i++)sum=sum % mod+((((n-i-1)*(n-i))/2)*m*m)%mod;
    for(lli i=0;i<=m-2;i++)sum=sum % mod+((((m-i-1)*(m-i))/2)*n*n)%mod;
    sum=sum*(nCrModPFermat(n*m-2,k-2,mod));
	cout<<sum%mod;
    return 0;
}