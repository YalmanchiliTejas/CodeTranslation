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
#define pe(x) cout<<x<<" ";
#define ps(x) cout<<fixed<<setprecision(25)<<x<<endl;
#define pu(x) cout<<x;
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

ll n,m,num,sum,a,b,c,d,e,f,g,h,i,j,k,w,ok,ng,l,q,ans;
ll x[500005],y[500005],z[500005];
ll dp[10005][105][3];
char s[500005],t[500005];
bool flag,dame;

void solve(ll i,ll sum,bool flag){
	//now looking i bit
	if(i == n){
		if(sum == 0){
			p("hoi");
			ans += 1;
		}
		return;
	}else if(!flag){
		for(int j=0;j<=9;j++){
			solve(i+1,(sum+j)%d,0);
		}
	}else{
		a = s[i] - '0';
		for(int j=0;j<a;j++){
			solve(i+1,(sum+j)%d,0);
		}
		solve(i+1,(sum+a)%d,1);
	}
}

int main(){
    cin >> s >> d;
	n = strlen(s);
	dp[0][0][1] = 1;
	for(i=0;i<n;i++){
		for(j=0;j<d;j++){
			for(k=0;k<=9;k++){
				dp[i+1][(j+k)%d][0] += dp[i][j][0];
				dp[i+1][(j+k)%d][0] %= mod;
			}
			a = s[i] - '0';
			for(k=0;k<a;k++){
				dp[i+1][(j+k)%d][0] += dp[i][j][1];
				dp[i+1][(j+k)%d][0] %= mod;
			}
			dp[i+1][(j+a)%d][1] += dp[i][j][1];
			dp[i+1][(j+a)%d][1] %= mod;
		}
	}
	for(i=0;i<=n;i++){
		for(j=0;j<d;j++){
			//pe(dp[i][j][0]);
		}
	//	el;
	}
	p((dp[n][0][0] + dp[n][0][1] + mod - 1) % mod);
	return 0;
}