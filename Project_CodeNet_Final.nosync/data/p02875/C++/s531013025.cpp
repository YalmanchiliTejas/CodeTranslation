#include <bits/stdc++.h>
#define ll long long int 
#define MOD 998244353

using namespace std;


ll modPow(ll x,ll n,ll mod){
	ll r=1;
	x = x%mod;
	while(n){
		if(n&1)r = (r*x)%mod;
		x = (x*x)%mod;
		n = n>>1;
	}
	return r;
}



ll gcd(ll a,ll b,ll &x,ll &y){
	if(a==0){
		x = 0;
		y = 1;
		return b;
	}
	ll x1,y1;
	ll g = gcd(b%a,a,x1,y1);
	x = y1 - (b/a)*x1;
	y = x1;
	return g;
}

vector<ll> sieve(ll n){
	ll i,j;
	ll A[n+1]={0};
	vector<ll> V;
	A[0] = 0;
	A[1] = 1;
	for(i=2;i<n;++i){
		if(A[i]==0)for(j=i;j<n;j+=i)if(A[j]==0)A[j] = i; 
	}
	for(i=0;i<n;++i){
		V.push_back(A[i]);
	}
	return V;
}

template <typename T, typename S> 
ostream& operator<<(ostream& os, const pair<T, S>& v) 
{
    os << "("<< v.first << "," 
           << v.second << ")"; 
      
    return os; 
} 


template <typename T> 
ostream& operator<<(ostream& os, const set<T>& v) 
{ 
    os << "debug : ["; 
    for (auto it : v) { 
        os << it; 
        if (it != *v.rbegin()) 
            os << ", "; 
    } 
    os << "]\n\n"; 
    return os; 
} 

template <typename T> 
ostream& operator<<(ostream& os, const vector<T>& v) 
{ 
    os << "debug : ["; 
    for (int i = 0; i < v.size(); ++i) { 
        os << v[i]; 
        if (i != v.size() - 1) 
            os << ", "; 
    } 
    os << "]\n\n"; 
    return os; 
}

template <typename T, typename S> 
ostream& operator<<(ostream& os, const map<T, S>& v) 
{ 
	os << "debug : \n";
    for (auto it : v)  
        os << it.first << " : " 
           << it.second << "\n\n"; 
      
    return os; 
} 

//	 vector<vector<ll> > V(n, vector<ll>(m, 0));
template <class T>
vector <vector<T> > mul(vector <vector<T> > &a, vector <vector<T> > &b,ll mod)
{
    const int n = a.size();     // a rows
    const int m = a[0].size();  // a cols
    const int p = b[0].size();  // b cols

    std::vector <std::vector<T>> c(n, std::vector<T>(p, 0));
    for (auto j = 0; j < p; ++j)
    {
        for (auto k = 0; k < m; ++k)
        {
            for (auto i = 0; i < n; ++i)
            {
                ll temp = (a[i][k] * b[k][j])%mod;
                c[i][j] = (c[i][j]+temp)%mod;
            }
        }
    }
    return c;
}


vector<vector<ll> > modPow(vector<vector<ll> > x,ll n,ll mod){
	vector<vector<ll> > r(x.size(), vector<ll> (x.size(),0));
	ll i,j;
	if(x.size()!=x[0].size()){
		cout<<"error :: \n\n";
	}
	for(i=0;i<x.size();++i)r[i][i]=1;

	while(n){
		if(n&1) r = mul(r,x,mod);
		x = mul(x,x,mod);
		n = n>>1;
	}
	return r;
}

//	Nth fibonacci 
// cin>>t;
// 	while(t--){
// 		cin>>k;
// 		n = 2;m = 2;	
// 		vector<vector<ll> > V(n, vector<ll>(m, 0));
// 		V[0][1] = 1;
// 		V[1][1] = V[1][0] = 1;

// 		vector<vector<ll> > temp = modPow(V,k,MOD);
// 		// for(auto it:temp)cout<<it;
// 		cout<<temp[1][0]<<"\n";
// 	}

bool prime(ll n){
	if(n==1) return false;
	if(n==2) return true;
	if(n%2==0)return false;
	ll r=0,d,i,j,k,l;
	l = n-1;
	while(l%2==0){l=l/2;r++;}
	d = l;
	vector<ll> A = {2,3,5,7,11,13,17,19,23};
	for(auto a:A){
		if(a>n-2) break;
		ll x = modPow(a,d,n);
		if(x==1||x==n-1) continue;
		bool test=false;
		for(i=0;i<r;++i){
			x = (x*x)%n;
			if(x==n-1){
				test=true;
				break;
			}
		}
		if(test)
			continue;
		return false;
	}
	return true;
}


bool check(string s){

	if(s.size()==0)
		return true;
	ll i,j;
	bool ans=false;
	for(i=0;i<s.size()-1;++i){
		if((s[i]=='A'&&s[i+1]=='B')||((s[i]=='B'&&s[i+1]=='A'))){

		}else{
			string p="";
			for(j=0;j<s.size();++j){
				if(j!=i&&j!=(i+1))p=p+s[j];
			}
			if(check(p))
				return true;
		}
	}
	return false;
}

bool check(ll x,ll n){
	string s="";
	while(n--){
		s = s+ char('A'+x%3);
		x = x/3;
	}
	// cout<<s<<" "<<check(s)<<"\n";
	if(check(s)){
		cout<<s<<"\n";
		return true;
	}
	return false;
}

ll count(ll n){
	ll l=1,r=3;
	ll x=n;
	while(--n){r=3*r;}
	ll ans=0;
	for(ll i=0;i<r;++i){
		if(check(i,x)){
			ans++;
		}
	}
	return ans;
}

int main(){
	ll t,i,j,k,l,n,m,x,y,a,b,c,r,q;
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	cin>>n;
	ll ans=1,mul=1;
	for(i=1;i<n/2;++i){
		mul = (mul*2)%MOD;
		mul = (mul*(n-i+1))%MOD;
		mul = (mul*modPow(i,MOD-2,MOD))%MOD;
		// cout<<mul<<"\n";
		ans=(ans+mul)%MOD;
	}
	ans = (2*ans)%MOD;
	ans = (modPow(3,n,MOD)-ans)%MOD;
	while(ans<0)ans+=MOD;
	cout<<ans;
	return 0;
}