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
#define pi 3.14159265358979323846
#define MOD 1000000007
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

bool b[100000];
void solve()
{
int n;
    string s;
    cin >> n >> s;
 
    for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++){
        bool fl = 0;
        b[0] = i;
        b[1] = j;
        for (int it = 1; it < n - 1; it++){
            if ((b[it] && s[it] == 'o') || (!b[it] && s[it] == 'x')){
                b[it + 1] = b[it - 1];
            }
            else{
                b[it + 1] = !b[it - 1];
            }
        }
 
        if ((b[n - 1] && s[n - 1] == 'o') || (!b[n - 1] && s[n - 1] == 'x')){
            if (b[0] != b[n - 2])
                fl = 1;
        }
        else{
            if (b[0] == b[n - 2])
                fl = 1;
        }
 
        for (int it = 0; it < n; it++){
            if (b[it] && s[it] == 'o'){
                if (b[(it - 1 + n) % n] != b[(it + 1) % n])
                    fl = 1;
            }
            if (b[it] && s[it] == 'x'){
                if (b[(it - 1 + n) % n] == b[(it + 1) % n])
                    fl = 1;
            }
 
            if (!b[it] && s[it] == 'o'){
                if (b[(it - 1 + n) % n] == b[(it + 1) % n])
                    fl = 1;
            }
            if (!b[it] && s[it] == 'x'){
                if (b[(it - 1 + n) % n] != b[(it + 1) % n])
                    fl = 1;
            }
        }
 
        if (!fl){
            for (int it = 0; it < n; it++)
                cout << (b[it] ? 'S' : 'W');
            return;
        }
    }
 
    cout << -1 << '\n';  
    return;
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
