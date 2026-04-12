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

const int ary=1e5+5;
const int mod=1e9+7;
const ll inf=1e18;

using namespace std;
using namespace __gnu_pbds;
int a,b;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>a>>b;
	if(a==b){
		cout<<"Yes";
		return 0;
	}
	cout<<"No";
}