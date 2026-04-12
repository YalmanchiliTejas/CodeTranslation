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
double Pi = 3.141592653589;
long long int mod = 1000000007;
// memset(a,0,sizeof(a)); →全部０にする
 
vector<ll> G[100005];
vector<P> tree[100010];
priority_queue <ll> pql;
priority_queue <P> pqp;
//big priority queue
priority_queue <ll,vector<ll>,greater<ll> > pqls;
priority_queue <P,vector<P>,greater<P> > pqps;
//small priority queue
//top pop

int dx[8]={1,0,-1,0,1,1,-1,-1};
int dy[8]={0,1,0,-1,1,-1,-1,1};
//↓,→,↑,←
 
#define p(x) cout<<x<<endl;
#define el cout<<endl;
#define pe(x) cout<<x<<" ";
#define ps(x) cout<<fixed<<setprecision(25)<<x<<endl;
#define pu(x) cout<<x;
#define re(i,a,b) for(i=a;i<=b;i++);
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define deba(x) cout<< #x << " = " << x <<endl

ll rui(ll abc,ll bed){
	//aのb乗を計算する
	if(bed==0){return 1;}
	else{
		ll ced = rui(abc,bed/2);
		ced *= ced;
		ced %= mod;
		if(bed%2==1){ced*=abc; ced%=mod;}
		return ced;
	}
} 

ll i,j,k,ii,jj;
ll n,m,num,sumxor,sum;
ll ans;
ll a,b,c,d,e,f,g,h,w,v;
char s[500005];
ll x[800005],y[800005],z[900005];
bool animal[500005];

int main(){	
	cin>>n;
	cin>>s;
	while(b<10){
		b++;
		//deba(b);
		animal[0]=b%2;
		animal[1]=(b/2)%2;
		for(i=1;i<n;i++){
			if(animal[i] && s[i]=='o'){
				animal[i+1] = animal[i-1];
			}else if(animal[i] && s[i]=='x'){
				animal[i+1] = !animal[i-1];
			}else if(!animal[i] && s[i]=='o'){
				animal[i+1] = !animal[i-1];
			}else{
				animal[i+1] = animal[i-1];
			}
		}
		//for(i=0;i<=n;i++){
		//	if(animal[i])pu('S');
		//	if(!animal[i])pu('W');
		//}
		//el;
		a=0;
		if(animal[0] == animal[n])a++;
		if(s[0]=='o' && animal[1]==animal[n-1] && animal[0])a++;
		if(s[0]=='x' && animal[1]!=animal[n-1] && animal[0])a++;
		if(s[0]=='o' && animal[1]!=animal[n-1] && !animal[0])a++;
		if(s[0]=='x' && animal[1]==animal[n-1] && !animal[0])a++;
		//deba(a);
		if(a<=1){
			continue;
		}else{
			for(i=0;i<n;i++){
				if(animal[i]){
					pu("S");
				}else{
					pu("W");
				}
			}
		}
		el;
		return 0;
	}
	p(-1);
	
	//p(ans);
	return 0;
}