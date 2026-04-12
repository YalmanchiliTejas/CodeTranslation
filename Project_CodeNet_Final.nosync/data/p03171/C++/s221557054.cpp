//long long -> ll
//http://web.mit.edu/~ecprice/acm/acm08/notebook.html#file12
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include<bits/stdc++.h>
typedef long long ll;
#define x first
#define y second
#define REP(i,sss,eee) for(long long i=sss;i<=eee;++i)
#define pb push_back
#define pii pair<long long,long long>
#define vi vector<long long>
#define speed ios_base::sync_with_stdio(0);cin.tie(0);
#define N 1000000007
using namespace __gnu_pbds;
using namespace std;
template <class T>
T MAX(T a, T b){return ((a>b)?a:b);}
template <class T>
T MIN(T a, T b){return ((a<b)?a:b);}
template <class T>
T MOD(T a){return ((a>=0)?a:(-1*a));}
template <class T>
void SWAP(T &a,T &b){T temp=a;a=b;b=temp;}
typedef tree<
long long,
null_type,
less<long long>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
long long ex(long long a, long long b){
	if(b==0||a==1){return 1;}
	if(a==0||b==1){return a;}
	long long tmp=ex(a,(b/2));
	if(b%2){return ((((tmp*tmp)%N)*a)%N);}
	else{return ((tmp*tmp)%N);}
}
long long inv(long long k){
	if(k==1){return 1;}
	else{return ex(k,N-2);}
}
/*****************default********************/
long long n;
std::vector<long long> inp(n,0);
std::vector<std::vector<long long>> dp;
std::vector<std::vector<bool>> b;
long long f(long long s, long long e)
{
	//cout<<s<<" "<<e<<" \n";
	if(b[s][e]){return dp[s][e];}
	if(s==e)
	{
		b[s][e]=1;
		dp[s][e]=inp[s];
		return dp[s][e];
	}
	b[s][e]=1;
	dp[s][e]=(inp[s]-f(s+1,e));
	dp[s][e]=MAX(dp[s][e],(inp[e]-f(s,e-1)));
	return dp[s][e];
}
int main(){
	cin>>n;
	inp.resize(n,0);
	dp.resize(n+1,std::vector<long long>(n+1,0));
	b.resize(n+1,std::vector<bool>(n+1,0));
	REP(i,0,n-1){cin>>inp[i];}
	cout<<f(0,n-1)<<"\n";
}