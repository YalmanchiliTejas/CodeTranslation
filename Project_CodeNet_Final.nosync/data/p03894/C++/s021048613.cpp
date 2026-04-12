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
#include <tuple>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

long long int INF = 3e18;
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
//ll bit[500005];
//↓,→,↑,←


#define p(x) cout<<x<<endl;
#define el cout<<endl;
#define pe(x) cout<<(x)<<" ";
#define ps(x) cout<<fixed<<setprecision(25)<<x<<endl;
#define pu(x) cout<<(x);
#define pd(x) cerr<<"//"<<(x)<<endl;
#define re(i,n) for(i=0;i<n;i++);
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define deba(x) cout<< #x << " = " << x <<endl


ll mod = 1000000007;
ll rui(ll number1,ll number2){
    if(number2 == 0){
        return 1;
    }else{
        ll number3 = rui(number1,number2 / 2);
        number3 *= number3;
        number3 %= mod;
        if(number2%2==1){
            number3 *= number1;
            number3 %= mod;
        }
        return number3;
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
void YES(bool condition){
    if(condition){
        p("YES");
    }else{
        p("NO");
    }
    return;
}
void Yes(bool condition){
    if(condition){
        p("Yes");
    }else{
        p("No");
    }
    return;
}

ll n,m,num,sum,ans,a,b,c,d,e,f,g,h,i,j,k,w,ok,ng,l,q;
ll x[500005],y[500005],z[500005];
ll dp[500005];
bool no[3005][3005];
char s[500005],t[500005];
bool flag,dame;

int main(){
    cin >> n >> k;
	for(i=0;i<k;i++){
		cin >> x[i] >> y[i];
	}
	dp[1] = 2;
	ll pos = 1;
	dp[2] = 1;
	for(i=0;i<k;i++){
		if(pos == x[i]){
			swap(dp[x[i]],dp[y[i]]);
			pos = y[i];
		}else if(pos == y[i]){
			swap(dp[x[i]],dp[y[i]]);
			pos = x[i];
		}else{
			swap(dp[x[i]],dp[y[i]]);
		}
		dp[pos - 1] = 1;
		dp[pos + 1] = 1;
	}
	for(i=1;i<=n;i++){
		if(dp[i] >= 1)ans++;
	}
	p(ans);

	return 0;
}