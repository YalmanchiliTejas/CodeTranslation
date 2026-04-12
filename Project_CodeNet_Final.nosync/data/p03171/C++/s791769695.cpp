#pragma comment(linker,"/stack:16777216")
#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<list>
#include<stack>
#include<queue>
#include<deque>
#include<functional>
#include<utility>
#include<algorithm>
#include<sstream>
#include<cstring>
#include<cmath>
#include<cctype>
#include<exception>
#include<climits>
#include<cfloat>
#include<iomanip>
#include<bitset>
#include<streambuf>
#include<cstdlib>
#include<ctime>
//#include"functions.h"
//#include"highprecision.h"
#define pb push_back
#define pf push_front
#define ppb pop_back
#define mp make_pair
#define np next_permutation
#define fi first
#define sc second
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int> >
#define vpi vector<pair<int,int> >
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pff pair<float,float>
#define pdd pair<double,double>
#define psi pair<string,int>
#define pis pair<int,string>
#define ppi pair<pii,int>
#define pdi pair<pii,pii>
#define LN 84757
#define INF 1e9
#define LLINF 1e18
#define MAXINT 0x7fffffff
#define MAXLL 0x7fffffffffffffff
#define EPS 1e-5
#define DEPS 1e-9
#define LDEPS 1e-13
#define MOD 1000000007
#define E 2.7182818284
#define PI 3.1415926535
#define rep(a,b) for(int a=0;a<b;a++)
#define rep(a,b) for(int a=0;a<b;a++)
#define forn(a,n) for(int a=1;a<=n;a++)
#define forr(a,n) for(int a=n;a>=1;a--)
#define repn(a,n,p) for(int a=0;a<n;a+=p)
#define repr(a,n) for(int a=n-1;a>=0;a--)
#define foreach(a,b) for(__typeof(b.begin())a=b.begin();a!=b.end();a++)
#define fillemp(a) memset(a,0,sizeof(a))
#define fillinf(a) memset(a,0x3f,sizeof(a))
#define frestream freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define stdf(a,b) freopen(a,"r",stdin);freopen(b,"w",stdout);
#define inputf(a) freopen(a,"r",stdin);
#define outputf(a) freopen(a,"w",stdout);
#define sz(a) a.size()
#define all(a) a.begin(),a.end()
#define MOD 1000000007
typedef long long ll;
typedef long double ld;
using namespace std;

int n;
ll a[3010];
ll dp[3010][3010];
int main(int argc,char** argv){
	cin>>n;
	rep(i,n){
		cin>>a[i];
	}
	bool flag=(n%2);
	rep(i,n){
		if(flag){
			dp[i][i]=a[i];
		}
		else{
			dp[i][i]=-a[i];
		}
	}
	for(int l=2;l<=n;l++){
		for(int i=0;i<=n-l;i++){
			int j=l+i-1;
			if((n-l)%2==1){
				dp[i][j]=min(dp[i+1][j]-a[i],dp[i][j-1]-a[j]);
			}
			else{
				dp[i][j]=max(dp[i+1][j]+a[i],dp[i][j-1]+a[j]);
			}
		}
	}
	cout<<dp[0][n-1]<<endl;
	return 0;
}