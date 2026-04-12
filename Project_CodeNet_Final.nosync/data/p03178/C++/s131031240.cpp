//long long -> ll
//http://web.mit.edu/~ecprice/acm/acm08/notebook.html#file12
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include<bits/stdc++.h>
typedef long long ll;
#define x first
#define y second
#define all(aaa) (aaa).begin(),(aaa).end()
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
long long solve()
{
	string k;long long d;cin>>k>>d;
	reverse(k.begin(),k.end());
	long long n=k.size();
	std::vector<std::vector<long long>> f(10003,std::vector<long long>(d,0));
	std::vector<long long> g(10003,0);
	long long tot=0;REP(i,0,n-1){(tot+=(k[i]-'0'));}
	if(tot%d==0){g[0]=1;}
	tot=((((tot-(k[0]-'0'))%d)+d)%d);
	long long highest=(k[0]-'0');
	for(long long i=0;i<highest;++i)
	{
		(f[0][i%d])++;
	}
	g[1]=g[1]+f[0][(d-tot)%d];
	for(long long i=highest;i<=9;++i)
	{
		(f[0][i%d])++;
	}
	for(long long i=1;i<n;++i)
	{
		tot=((((tot-(k[i]-'0'))%d)+d)%d);
		highest=(k[i]-'0');
		g[i]=(g[i]+g[i-1])%N;
		for(long long val=0;(val<highest);++val)
		{
			for(long long rem=0;rem<d;++rem){f[i][(val+rem)%d]=(f[i][(val+rem)%d]+f[i-1][rem])%N;}
		}
		g[i+1]=((g[i+1]+f[i][(d-tot)%d])%N);
		for(long long val=highest;(val<10);++val)
		{
			for(long long rem=0;rem<d;++rem){f[i][(val+rem)%d]=(f[i][(val+rem)%d]+f[i-1][rem])%N;}
		}
	}
	//cout<<g[n]<<" "<<g[n-1]<<"\n";
	cout<<((g[n]+g[n-1]-1)%N)<<"\n";
}
signed main(){
	speed
	long long tt=1;
	//cin>>tt;
	while(tt--)
	{
		solve();
	}
	return 0;
}