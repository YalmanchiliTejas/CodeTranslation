#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll unsigned long long
//increase stack size
#pragma comment(linker, "/STACK:16777216")

// ll mxm() {return LLONG_MIN;}
// template<typename... Args>
// ll mxm(ll a, Args... args) { return max(a,mxm(args...)); }

// ll mnm() {return LLONG_MAX;}
// template<typename... Args>
// ll mnm(ll a, Args... args) { return min(a,mnm(args...)); }

template<class T> ostream& operator<<(ostream& os,vector<T> V){
	os<<"[ ";for(auto v:V)os<<v<<" ";return os<<"]";
}
template<class L,class R> ostream& operator<<(ostream& os,pair<L,R> P){
	return os<<"("<<P.first<<","<<P.second<<")";
}

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__,__VA_ARGS__)
template<typename Arg1>
void __f(const char* name,Arg1&& arg1){
	cout<<name<<" : "<<arg1<<endl;
}
template <typename Arg1,typename... Args>
void __f(const char* names,Arg1&& arg1,Args&&... args){
	const char* comma=strchr(names+1,',');cout.write(names,comma-names)<<" : "<<arg1<<" | ";__f(comma+1,args...);
}
#else
#define trace(...) 1
#endif

#define ld long double
#define pll pair<ll,ll>
#define ii pair<int,int>
#define vll vector<ll>
#define vii vector<ii>
#define vi vector<int>
#define vpll vector<pll>
#define vld vector<ld>
#define vvld vector<vld>
#define vvi vector<vi>
#define vvll vector<vll>
#define vvpll vector<vpll>
#define vvii vector<vii>
#define I insert
#define F first
#define S second
#define pb push_back
#define endl "\n"
#define all(x)	x.begin(),x.end()

const int mod=1e9+7;
// 128 bit: __int128
inline int add(int a,int b){a+=b;if(a>=mod)a-=mod;return a;}
inline int sub(int a,int b){a-=b;if(a<0)a+=mod;return a;}
inline int mul(int a,int b){return (a*1ull*b)%mod;}
inline int power(int a,int b){int rt=1;while(b>0){if(b&1)rt=mul(rt,a);a=mul(a,a);b>>=1;}return rt;}
inline int inv(int a){return power(a,mod-2);}

struct compare{
	bool operator() (const int &a,const int &b) const{
		return a>b;
	}
};

const ll N = 500;
vll s(N), t(N), u(N), v(N);
vvll ans(N, vll(N));
ll n;

int solve(ll bit){
	vvi temp(n, vi(n, -1));
	vi satisfyr(n), satisfyc(n), remc(n), remr(n);
	for(ll i = 0; i < n; i++){
		ll b = (u[i] & (1ull << bit)) > 0, b1 = (v[i] & (1ull << bit)) > 0;
		if(!s[i]){
			if(b){
				for(int j = 0; j < n; j++)
					if(temp[i][j] == 0)
						return 0;
					else temp[i][j] = 1;
				satisfyr[i] = 1;
			}
			else{
				for(int j = 0; j < n; j++)
					if(temp[i][j] == 0)
						satisfyr[i] = 1;
			}
		}
		else{
			if(!b){
				for(int j = 0; j < n; j++)
					if(temp[i][j] == 1)
						return 0;
					else temp[i][j] = 0;
				satisfyr[i] = 1;
			}
			else{
				for(int j = 0; j < n; j++)
					if(temp[i][j] == 1)
						satisfyr[i] = 1;
			}
		}

		if(!t[i]){
			if(b1){
				for(int j = 0; j < n; j++)
					if(temp[j][i] == 0)
						return 0;
					else temp[j][i] = 1;
				satisfyc[i] = 1;
			}
			else{
				for(int j = 0; j < n; j++)
					if(temp[j][i] == 0)
						satisfyc[i] = 1;
			}
		}
		else{
			if(!b1){
				for(int j = 0; j < n; j++)
					if(temp[j][i] == 1)
						return 0;
					else temp[j][i] = 0;
				satisfyc[i] = 1;
			}
			else{
				for(int j = 0; j < n; j++)
					if(temp[j][i] == 1)
						satisfyc[i] = 1;
			}
		}
	}

	for(ll i = 0; i < n; i++){
		ll b = (u[i] & (1ull << bit)) > 0, b1 = (v[i] & (1ull << bit)) > 0;
		if(!s[i]){
			if(b){
				for(int j = 0; j < n; j++)
					if(temp[i][j] == 0)
						return 0;
					else temp[i][j] = 1;
				satisfyr[i] = 1;
			}
			else{
				for(int j = 0; j < n; j++)
					if(temp[i][j] == 0)
						satisfyr[i] = 1;
			}
		}
		else{
			if(!b){
				for(int j = 0; j < n; j++)
					if(temp[i][j] == 1)
						return 0;
					else temp[i][j] = 0;
				satisfyr[i] = 1;
			}
			else{
				for(int j = 0; j < n; j++)
					if(temp[i][j] == 1)
						satisfyr[i] = 1;
			}
		}

		if(!t[i]){
			if(b1){
				for(int j = 0; j < n; j++)
					if(temp[j][i] == 0)
						return 0;
					else temp[j][i] = 1;
				satisfyc[i] = 1;
			}
			else{
				for(int j = 0; j < n; j++)
					if(temp[j][i] == 0)
						satisfyc[i] = 1;
			}
		}
		else{
			if(!b1){
				for(int j = 0; j < n; j++)
					if(temp[j][i] == 1)
						return 0;
					else temp[j][i] = 0;
				satisfyc[i] = 1;
			}
			else{
				for(int j = 0; j < n; j++)
					if(temp[j][i] == 1)
						satisfyc[i] = 1;
			}
		}
	}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(temp[i][j] == -1)
				remr[i]++, remc[j]++;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(temp[i][j] != -1) continue;
			ll b = (u[i] & (1ull << bit)) > 0, b1 = (v[j] & (1ull << bit)) > 0;
			if(satisfyc[j] && satisfyr[i]){
				temp[i][j] = 0;
				remr[i]--, remc[j]--;
				continue;
			}
			if(satisfyr[i] && !satisfyc[j]){
				satisfyc[j] = 1;
				temp[i][j] = t[j];
				remr[i]--, remc[j]--;
				continue;
			}
			if(satisfyc[j] && !satisfyr[i]){
				satisfyr[i] = 1;
				temp[i][j] = s[i];
				remr[i]--, remc[j]--;
				continue;
			}
			if(s[i] == t[j]){
				temp[i][j] = s[i];
				satisfyr[i] = satisfyc[j] = 1;
				remr[i]--, remc[j]--;
				continue;
			}
		}
	}

	queue<ii> q;
	for(int i = 0; i < n; i++){
		if(satisfyr[i])
			q.push({i, 0});
		if(satisfyc[i])
			q.push({i, 1});
	}
	while(!q.empty()){
		auto a = q.front();
		q.pop();
		int x = a.F, y = a.S;
		if(y == 0){
			for(int j = 0; j < n; j++){
				if(satisfyc[j] || temp[x][j] > -1)
					continue;
				satisfyc[j] = 1;
				temp[x][j] = t[j];
				--remr[x], --remc[j];
				q.push({j, 1});
			}
		}
		else{
			for(int i = 0; i < n; i++){
				if(satisfyr[i] || temp[i][x] > -1)
					continue;
				temp[i][x] = s[i];
				--remr[i], --remc[x];
				satisfyr[i] = 1;
				q.push({i, 0});
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(temp[i][j] != -1) continue;
			ll b = (u[i] & (1ull << bit)) > 0, b1 = (v[j] & (1ull << bit)) > 0;
			if(satisfyc[j] && satisfyr[i]){
				temp[i][j] = 1;
				continue;
			}
			if(satisfyr[i] && !satisfyc[j]){
				satisfyc[j] = 1;
				temp[i][j] = t[j];
				continue;
			}
			if(satisfyc[j] && !satisfyr[i]){
				satisfyr[i] = 1;
				temp[i][j] = s[i];
				continue;
			}
			if(s[i] == t[j]){
				temp[i][j] = s[i];
				satisfyr[i] = satisfyc[j] = 1;
				continue;
			}
			if(remr[i] <= remc[j])
				temp[i][j] = s[i], satisfyr[i] = 1;
			else temp[i][j] = t[j], satisfyc[j] = 1;
			--remr[i], --remc[j];
		}
	}

	for(int i = 0; i < n; i++){
		if(!satisfyr[i] || !satisfyc[i])
			return 0;
		for(int j = 0; j < n; j++)
			if(temp[i][j])
				ans[i][j] += (1ull << bit);
	}
	return 1;
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<setprecision(25);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> s[i];
	for(int i = 0; i < n; i++)
		cin >> t[i];
	for(int i = 0; i < n; i++)
		cin >> u[i];
	for(int i = 0; i < n; i++)
		cin >> v[i];
	for(ll i = 0; i <= 63; i++){
		if(!solve(i)){
			cout << -1 << endl;
			return 0;
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			cout << ans[i][j] << ' ';
		cout << endl;
	}
}