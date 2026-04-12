#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<cassert>
#include<cassert>
#include<unordered_map>
#include<unordered_set>
#include<functional>
#include<queue>
#include<stack>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<sstream>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<numeric>
#include<random>
#include<chrono>
#include<bitset>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define xx first
#define yy second
#define sz(x) (int)(x).size()
#define gc getchar
#define IO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define mp make_pair

#ifndef ONLINE_JUDGE
#  define LOG(x) (cerr << #x << " = " << (x) << endl)
#else
#  define LOG(x) ((void)0)
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double PI=3.1415926535897932384626433832795;
const ll INF = 1LL<<62;
const ll MINF = -1LL<<62;

template<typename T> T getint() {
	T val=0;
	char c;
	
	bool neg=false;
	while((c=gc()) && !(c>='0' && c<='9')) {
		neg|=c=='-';
	}

	do {
		val=(val*10)+c-'0';
	} while((c=gc()) && (c>='0' && c<='9'));

	return val*(neg?-1:1);
}

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); uniform_int_distribution<int>(0, n-1)(rng)

int n;
ull s[501], t[501], u[501], v[501], uu[501], vv[501];
ull ans[501][501];
void no() {
	cout<<"-1\n";
	exit(0);
}
int main() {
	IO;
	cin>>n;
	for(int i=0;i<n;++i) cin>>s[i];
	for(int i=0;i<n;++i) cin>>t[i];
	for(int i=0;i<n;++i) cin>>u[i],uu[i]=u[i];
	for(int i=0;i<n;++i) cin>>v[i],vv[i]=v[i];;
	vector<int> sor,osz;
	for(int i=0;i<n;++i) {
		if(s[i]==0) sor.pb(i);
		if(t[i]==0) osz.pb(i);
		
		for(int j=0;j<n;++j) {
			if(s[i]==t[j]) {
				if(s[i]==0) {
					ans[i][j]=u[i]|v[j];
				}else {
					ans[i][j]=u[i]&v[j];
					//~ u[i]^=ans[i][j];
					//~ v[j]^=ans[i][j];
				}
			}else {
				if(s[i]==0) {
					ans[i][j]=u[i];
					//~ ll common=u[i]&v[j];
					//~ v[j]^=common;
				}else {
					ans[i][j]=v[j];
					//~ ll common=u[i]&v[j];
					//~ u[i]^=common;
				}
				
			}
		}
	}
	
	//~ for(int i=0;i<n;++i) {
		//~ for(int j=0;j<n;++j) {
			//~ cerr<<ans[i][j]<<" \n"[j==n-1]; 
		//~ }
	//~ }
	
	random_shuffle(all(sor));
	random_shuffle(all(osz));
	

	int ind;
	
	ind=0;
	for(int i=0;i<n;++i) {
		if(s[i]==1) {
			ull res=0;
			for(int j=0;j<n;++j) {
				res|=ans[i][j];
			}
			if((res&(u[i]))!=res) no();
			u[i]^=res;
			
			if(u[i]>0) {
				if(osz.empty()) no();
				for(;;ind=(ind+1)%sz(osz)) {
					ull res=~0;
					for(int j=0;j<n;++j) {
						if(j!=i) res&=ans[j][osz[ind]];
					}
					if((res&u[i]&v[osz[ind]])==0) break ;
				}
				ans[i][osz[ind]]|=u[i];
				u[i]=0;
				ind=(ind+1)%sz(osz);
			}
		}
	}
	
	//~ for(int i=0;i<n;++i) {
		//~ for(int j=0;j<n;++j) {
			//~ cerr<<ans[i][j]<<" \n"[j==n-1]; 
		//~ }
	//~ }
	
	ind=0;
	for(int i=0;i<n;++i) {
		if(t[i]==1) {
			ull res=0;
			for(int j=0;j<n;++j) {
				res|=ans[j][i];
			}
			if((res&(v[i]))!=res) no();
			v[i]^=res;
			
			if(v[i]>0) {
				if(sor.empty()) no();
				for(;;ind=(ind+1)%sz(osz)) {
					ull res=~0;
					for(int j=0;j<n;++j) {
						if(j!=i) res&=ans[sor[ind]][j];
					}
					if((res&v[i]&u[sor[ind]])==0) break ;
				}
				ans[sor[ind]][i]|=v[i];
				v[i]=0;
				ind=(ind+1)%sz(sor);
			}
		}
	}

	
	bool valid=true;
	for(int i=0;i<n;++i) {
		ull res=ans[i][0];
		for(int j=0;j<n;++j) {
			if(s[i]==0) {
				res=res&ans[i][j];
			}else {
				res=res|ans[i][j];
			}
		}
		
		valid&=res==uu[i];
	}
	
	for(int i=0;i<n;++i) {
		ull res=ans[0][i];
		for(int j=0;j<n;++j) {
			if(t[i]==0) {
				res=res&ans[j][i];
			}else {
				res=res|ans[j][i];
			}
		}
		
		valid&=res==vv[i];
	}
	
	if(!valid) {
		cout<<"-1\n";
		exit(0);
	}
	
	for(int i=0;i<n;++i) {
		for(int j=0;j<n;++j) {
			cout<<ans[i][j]<<" \n"[j==n-1]; 
		}
	}
	
	return 0;
}
