#include<bits/stdc++.h>
// #include <boost/lexical_cast.hpp>
using namespace std;


#define ll long long int
#define vll vector<ll>
#define vllv vector<vector<ll>> 
#define sz size()
#define pb push_back
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

ll ceil1(ll n,ll m){if(n%m==0){return n/m;}return n/m +1;}
vll factor(ll n){
    vll ans;
    if(n>0)ans.pb(1);if(n==2)ans.pb(2);
    for(ll i=2;i*i<=n;i++){if(n%i==0){ans.pb(i);if(n/i!=i)ans.pb(n/i);}}if(n>2)ans.pb(n);
    return ans;
}
ll fact(ll n){
	
    ll res = 1; 
    for (ll i = 2; i <= n; i++) 
        res = res * i; 
    return res; 
} 
  
int nCr(ll n, ll r) 
{ 
    return fact(n) / (fact(r) * fact(n - r)); 
} 
  
void dfs(vllv &v,ll k,vll &par,vll &dis,ll p)
{
 
    par[k]=p;
    dis[k]=dis[p]+1;
    for(ll i=0;i<v[k].sz;i++){
        if(v[k][i]!=p){
            dfs(v,v[k][i],par,dis,k);
        }
    }
}
bool sortbysec(const pair<string,int> &a,const pair<string,int> &b){return (a.second<b.second);} 


ll ston(string s) 
{ 
    stringstream geek(s); 
    ll x = 0; 
    geek >> x; 
    
  
    return x; 
}
ll pow2(ll n,ll k){ll ans=1;
    while(k>0){
        if(k%2==1)ans=ans*n;n=n*n;k/=2;
    }return ans;}
bool prime(int n){
    int i,j;
    for(i=2;i<=sqrt(n);i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
bool bserch(vector<string> a, string s){
	
	ll l=0,r=a.sz-1,mid;
	while(l<=r){
		mid=(l+r)/2;
		if(a[mid]==s)return true;
		if(a[mid]<s){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	return false;
}

bool sortcol( const vector<int>& v1, 
               const vector<int>& v2 ) { 
 return v1[0] < v2[0]; 
} 

 ll degit(ll n)
 {
 	ll t=0;
 	while(n>0)
 	{
 		t++;
 		n/=10; 	}
 		return t;
 }
 

void solve()
{
	ll n, a[114][514] = {0};
	cin>>n;
	string s;
	for(int i=0;i<n;i++)
	{
    	cin>>s;
    	for(int j=0;j<s.size();j++)
    		a[i][s[j]-97]++;
	}
	for(int j=0;j<26;j++)
	{
    	a[n][j]=810;
    	for(int i=0;i<n;i++)
    	{
    		a[n][j]=min(a[n][j],a[i][j]);
    	}
    	for(int i=0;i<a[n][j];i++)
    		cout<<(char)(97+j);
  }
  cout<<endl;
	
}
	

int main()
{
	fast;
    ll q;
    q=1;
    // cin>>q;
    while(q--)
    {
        solve();
    }
    return 0;
}