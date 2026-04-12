#include <bits/stdc++.h>
#include <iomanip>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define FAST std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define DECIMAL(n)  std::cout << std::fixed;std::cout << std::setprecision(n);
#define hell 1000000007
#define narak 998244353
#define PI 3.14159265358979323844
#define mp make_pair
#define eb emplace_back
#define pb push_back
#define fi first 
#define se second
#define ALL(v) v.begin(), v.end()
#define SORT(v) sort(ALL(v))  
#define REVERSE(v) reverse(ALL(v))
#define endl "\n"
#define maxc(v) *max_element(ALL(v))
#define minc(v) *min_element(ALL(v))
#define sqr(a) (a)*(a)
#define GCD(m,n) __gcd(m,n)
#define LCM(m,n) m*(n/GCD(m,n))
#define inputarr(a,n) for(int xxx=0;xxx<n;++xxx) cin>>a[xxx]
#define initarr(a,n,x) for (int xxx=0;xxx<n;++xxx) a[xxx]=x
#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define sz(a) (int)a.size()
#define sl(a) (int)a.length()
#define invect(data,n,commands) for(int xxx = 0;xxx<n;xxx++){int tmp;cin>>tmp;data.pb(tmp);commands}
#define inset(data,n,commands) for(int xxx = 0;xxx<n;xxx++){int tmp;cin>>tmp;data.insert(tmp);commands}
#define display(x) trav(a,x) cout<<a<<" ";cout<<endl
#define debug cerr<<"bhau"<<endl
#define between(n,a,b) (a<=n&&n<=b)
#define clamp(n,a,b) (((n)<(a))?(a):(((n)>(b))?(b):(n))) 

#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    std::cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');std::cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}

template<typename T, typename U> static inline void amin(T &x, U y) 
{ 
    if (y < x) 
        x = y; 
}
template<typename T, typename U> static inline void amax(T &x, U y) 
{ 
    if (x < y) 
        x = y; 
}

std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

#define ll long long
#define ld long double 
#define pii std::pair<int, int> 
#define pll std::pair<ll, ll>  
#define vi vector<int>  
#define vvi vector<vi > 
#define vii vector<pii >
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

/*----------------------Graph Moves----------------*/
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/

//primes for hashing 937,991,1013,1409,1741

pii operator+(pii a, pii b)
{
	return {a.fi+b.fi,a.se+b.se};
}
pll operator+(pll a, pll b)
{
	return {a.fi+b.fi,a.se+b.se};
}
std::ostream& operator<<(std::ostream& out,pii a)
{
	out<<a.fi<<" "<<a.se<<endl;
	return out;
}
std::ostream& operator<<(std::ostream& out,pll a)
{
	out<<a.fi<<" "<<a.se<<endl;
	return out;
}
std::istream& operator>>(std::istream& in,pii &a)
{
    in>>a.fi>>a.se;
    return in;
}
std::istream& operator>>(std::istream& in,pll &a)
{
    in>>a.fi>>a.se;
    return in;
}

using namespace std;
using namespace __gnu_pbds;
void meowmeow321()
{
	string k;
	cin>>k;
	int n=sl(k);
	int d;
	cin>>d;
	ll dp[n][d][2];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < d; ++j)
		{
			dp[i][j][0]=0;
			dp[i][j][1]=0;
		}
	}
	for (int i = 0; i < 10; ++i)
	{
		if(i<(k[0]-'0'))dp[0][i%d][1]+=1;
		else if(i==(k[0]-'0'))dp[0][i%d][0]+=1;
	}
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < d; ++j)
		{
			for (int dig = 0; dig < 10; ++dig)
			{
				if(dig==(k[i]-'0')){
					dp[i][j][0]+=dp[i-1][(j-dig+10*d)%d][0];
					dp[i][j][0]%=hell;
					dp[i][j][1]+=dp[i-1][(j-dig+10*d)%d][1];
					dp[i][j][1]%=hell;
				}
				else if(dig<(k[i]-'0')){
					dp[i][j][1]+=dp[i-1][(j-dig+10*d)%d][0]+dp[i-1][(j-dig+10*d)%d][1];
					dp[i][j][1]%=hell;
				}else{
					dp[i][j][1]+=dp[i-1][(j-dig+10*d)%d][1];
					dp[i][j][1]%=hell;
				}
			}
			// trace(i,j,dp[i][j][0],dp[i][j][1]);
		}
	}
	cout<<(dp[n-1][0][0]+dp[n-1][0][1]-1+hell)%hell<<endl;
}
int main()
{
    FAST;
    int testcases=1;
    //cin>>testcases;
    for(int i=0;i<testcases;++i)
    {
    	meowmeow321();
    }
    return 0;
}