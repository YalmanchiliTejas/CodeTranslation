//#pragma GCC target ("avx2")
//#pragma GCC optimization ("Ofast")
//#pragma GCC optimization ("unroll-loops")

//#pragma comment(linker,"/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

//order_of_key(k): Number of items strictly smaller than k .
//find_by_order(k): K-th element in a set (counting from zero).
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define full(x,n) x,x+n+1
#define full(x) x.begin(),x.end()
#define finish return 0

#define putb push_back
#define f first
#define s second

//logx(a^n)=loga(a^n)/logx(a)
//logx(a*b)=logx(a)+logx(b)
//logx(y)=log(y)/log(x)
//logb(n)=loga(n)/loga(b)

#define ordered_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
#define putf push_front
#define gainb pop_back

#define gainf pop_front
#define len(x) (int)x.size()

// 1/b%mod=b^(m-2)%mod
// (a>>x)&1==0
// a^b=(a+b)-2(a&b)

typedef double db;
typedef long long ll;

//sum of squares n*(n+1)*(2n+1)/6
//sum of cubes [n*(n+1)/2]^2
//sum of squares for odds n*(4*n*n-1)/3
//sum of cubes for odds n*n*(2*n*n-1)

const int ary=1e5+5;
const int mod=1e9+7;
const ll inf=1e18;

using namespace std;
using namespace __gnu_pbds;
string k;
int D;
ll dp[ary][105],d[ary][105][2],ans;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>k>>D;
	dp[0][0]=1;
	for(int i=0;i<len(k)-1;i++){
		for(int j=0;j<D;j++){
			for(int p=0+(i==0);p<=9;p++){
				int t=(j+p)%D;
				dp[i+1][t]+=dp[i][j];
				dp[i+1][t]%=mod;
			}
		}
		ans+=dp[i+1][0];
		ans%=mod;
	}
	d[0][0][0]=1;
	for(int i=1;i<=len(k);i++){
		for(int j=0+(i==1);j<=9;j++){
			for(int p=0;p<D;p++){
				d[i][(p+j)%D][1]+=d[i-1][p][1];
				d[i][(p+j)%D][1]%=mod;
				if(j<k[i-1]-'0'){
					d[i][(p+j)%D][1]+=d[i-1][p][0];
				}
				else if(j==k[i-1]-'0'){
					d[i][(p+j)%D][0]+=d[i-1][p][0];
					d[i][(p+j)%D][0]%=mod;
				}
			}
		}
	}
	ans+=d[len(k)][0][0]+d[len(k)][0][1];
	ans%=mod;
	cout<<ans;
}