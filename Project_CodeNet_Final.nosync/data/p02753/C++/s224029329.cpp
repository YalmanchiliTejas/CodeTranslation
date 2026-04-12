#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<vector>
#include<list>
#include<cmath>
#include<algorithm>
#include<bitset>
#define lson node<<1,st,mid
#define rson node<<1|1,mid+1,ed
#define mem(a,x) memset(a,x,sizeof(a))
#define me(a) memset(a,0,sizeof(a))
#define IOS ios::sync_with_stdio(false)
#define lowbit(x) x&(-x)
#define up(i,x,y) for(long long i=x;i<y;i++)
#define down(i,x,y) for(long long i=x;i>=y;i--)
#define in freopen("in.txt","r",stdin)
#define out freopen("out.txt","w",stdout)   
typedef long long ll;
const ll mod = 998244353;
const ll INF = 0x3f3f3f3f;
const ll maxn = 2e5 + 5;
const double pi = acos(-1.0);
const double eps=1e-9;
using namespace std;
ll qpow(ll a, ll b) { ll s = 1; while (b > 0) { if (b & 1)s = s * a % mod; a = a * a % mod; b >>= 1; }return s; }
 
int main(){
	// in;
	// out;
	string s;
	cin>>s;
	int a=0,b=0;
	for(int i=0;i<s.length();i++){
		if(s[i]=='A') a++;
		else b++;
	}
	if(a==2||b==2) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}