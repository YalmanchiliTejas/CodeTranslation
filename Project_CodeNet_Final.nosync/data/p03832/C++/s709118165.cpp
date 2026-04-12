#include <iostream>
#include <cassert>
#include <climits>
#include <bitset>
#include <stack>
#include <queue>
#include <iomanip>
#include <limits>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

long long int INF = 1e18;
long long int mod = 1000000007;
double Pi = 3.1415926535897932384626;

vector<ll> G[500005];
vector<P> tree[500010];
priority_queue <ll> pql;
priority_queue <P> pqp;
//big priority queue
priority_queue <ll,vector<ll>,greater<ll> > pqls;
priority_queue <P,vector<P>,greater<P> > pqps;
//small priority queue
//top pop

int dx[8]={1,0,-1,0,1,1,-1,-1};
int dy[8]={0,1,0,-1,1,-1,-1,1};
char dir[] = "DRUL";
//↓,→,↑,←

#define p(x) cout<<x<<endl;
#define el cout<<endl;
#define pe(x) cout<<x<<" ";
#define ps(x) cout<<fixed<<setprecision(15)<<x<<endl;
#define pu(x) cout<<x;
#define re(i,n) for(i=0;i<n;i++);
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define deba(x) cout<< #x << " = " << x <<endl

ll rui(ll abc,ll bed){
    //abcのbed乗を計算する
    if(bed==0){return 1;}
    else{
        ll ced = rui(abc,bed/2);
        ced *= ced;
        ced %= mod;
        if(bed%2==1){ced*=abc; ced%=mod;}
        return ced;
    }
}
ll gcd(ll number1,ll number2){
	if(number1 > number2){
		swap(number1,number2);
	}
	if(number1 == 0 || number1 == number2){
		return number2;
	}else{
		return gcd(number2 % number1,number1);
	}
}

ll i,j,k,ii,jj,r,l;
ll n,m,num,sum,ans;
ll a,b,c,d,e,g,h,w;
ll x[500005],y[500005],z[1000005];
bool edge[20][20];
bool flag,dame;
char s[1000005];
ll kai[1005];
ll dp[2000][2000];
ll ncr[2000][2000];

int main(){	
	cin >> n >> a >> b >> c >> d;
	dp[0][0] = 1;
	kai[0] = 1;
	kai[1] = 1;
	for(i=2;i<=2000;i++){
		kai[i] = rui(i,mod-2);
		kai[i] %= mod;
		//pe(i);p(kai[i]);
	}
	ncr[0][0] = 1;
	for(i=1;i<=1000;i++){
		for(j=0;j<=i;j++){
			if(j == 0 || i == j){
				ncr[i][j] = 1;
			}else{
				ncr[i][j] = ncr[i-1][j-1] + ncr[i-1][j];
				ncr[i][j] %= mod;
			}
			//pe(ncr[i][j]);
		}
		//el;
	}
	for(i=0;i<=b-a;i++){
		num = i + a;
		for(j=0;j<=n;j++){
			dp[i+1][j] += dp[i][j];
			dp[i+1][j] %= mod;
			if(n-j < num * c)continue;
			ll nokori = n-j;
			e = 1;
			for(k=1;k<=d;k++){
				if(nokori < num)break;
				e *= ncr[nokori][num];
				e %= mod;
				e *= kai[k];
				e %= mod;
				//p(e);
				nokori -= num;
				if(j + num * k > n)break;
				if(k >= c && j + num * k <= n){
					dp[i+1][j+num*k] += (dp[i][j]*e)%mod;
					dp[i+1][j+num*k] %= mod;
				}

			}
		}
	}
	//p(dp[0][0]);
	for(i=0;i<=b-a+1;i++){
		for(j=0;j<=n;j++){
		//	pe(dp[i][j]);
		}
		//el;
	}
	p(dp[b-a+1][n]);

	return 0;

}