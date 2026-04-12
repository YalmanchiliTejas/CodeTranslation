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
#include <time.h>

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
#define hoge cout << hoge << endl;
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
ll a,b,c,d,e,f,g,h,w;
ll x[1000005],y[1000005],z[1000005];
ll dp[8000][6000];
bool flag,dame;
ll dan[100],pate[100];



void solve(ll n,ll k){
	//pe(n);p(k);
	if(k <= 0)return;
	if(k >= dan[n]){
		ans += pate[n];
		return;
	}
	if(n == 0){
		ans += 1;
		return;
	}else{
		solve(n-1,k-1);
		if(k >= dan[n-1] + 2)ans += 1;
		solve(n-1,k-2-dan[n-1]);
	}
	return;
}



int main(){
	cin >> n >> k;
	dan[0] = 1;
	pate[0] = 1;
	for(i=1;i<=50;i++){
		dan[i] = 2 * dan[i-1] + 3;
		pate[i] = 2 * pate[i-1] + 1;
	}
	solve(n,k);
	p(ans);
	return 0;
}