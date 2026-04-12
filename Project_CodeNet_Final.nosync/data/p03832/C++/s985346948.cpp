//Shubham Vijayvargiya

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define pb push_back
#define mp make_pair
#define eb emplace_back
#define F first
#define S second
#define sz(a) (int)(a.size())
#define set(a,b) memset(a,b,sizeof(a))
#define let(x,a) __typeof(a) x(a)
#define rep(i, begin, end) for (ll i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define all(v) (v).begin(),(v).end()
#define sll(x) { scanf("%lld",&x); }
#define si(x) { scanf("%d",&x); }
#define slf(x) { scanf("%lf",&x); }
#define pll(x) { printf("%lld\n",x); }
#define pi(x) { printf("%d\n",x); }
#define tcases() long long testcases; cin>>testcases ; while(testcases--)

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << " = " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " = " << arg1<<" | ";__f(comma+1, args...);
}

#else
#define trace(...)
#endif

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<long long,long long> pll;
typedef vector<long long> vll;
typedef vector<pll> vpll;
typedef vector<vll> vvll;

const ll mod=1000000007;
//-----------------------------------------------------------------------------------------------------------------------------------------------//
#define N 1009
ll dp[N][N],ncr[N][N],dp2[N][N];

ll powmod(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1){
			res=(res*a)%mod;
		}
		b>>=1;
		a=(a*a)%mod;
	}
	return res;
}

int main()
{
//	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	ll n,a,b,c,d;
	sll(n);sll(a);sll(b);sll(c);sll(d);

	ncr[0][0]=ncr[1][0]=ncr[1][1]=1;
	rep(i,2,n+2){
		ncr[i][i]=1;
		ncr[i][0]=1;
		rep(j,1,i){
			ncr[i][j]=(ncr[i-1][j]+ncr[i-1][j-1])%mod;
		}
	}

	rep(i,0,n+2){
		dp2[i][1]=1;		
	}

	rep(i,2,n+2){
		rep(j,1,n+2){
			if(j*i<N){
				dp2[j][i]=(dp2[j][i-1]*ncr[j*i][j])%mod;
				dp2[j][i]=(dp2[j][i]*powmod(i,mod-2))%mod;
			}
		}
	}

	rep(i,0,n+2){
		rep(j,0,n+2){
			dp[i][j]=0;
		}
	}
	dp[0][a-1]=1;
	rep(i,a,b+1){
		rep(j,0,n+1){
			if(j==0){
				dp[j][i]=1;
				continue;
			}
			dp[j][i]=dp[j][i-1];
			rep(k,c,d+1){
//				trace(k);
				if((k*i)>j)
					break;
//				trace(i,j,k);
				ll temp=(dp[j-k*i][i-1]*ncr[j][k*i])%mod;
				temp=(temp*dp2[i][k])%mod;
				dp[j][i]+=temp;
				dp[j][i]%=mod;
			}
		}
	}
	cout<<dp[n][b]<<endl;
	return 0;
}