#include<bits/stdc++.h>
using namespace std;
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
#define MOD (int)1e9+(int)7
#define INF 2147483647
typedef long long ll;
typedef unsigned long long ull;

//dark power
//#define int ll
//define Error、大抵は、セミコロン忘れとか、Defineは関係ない
/*
vector<int> d(100000);
vector<int> b(100000);
class UnionFind{
	public:
	UnionFind(signed n){rep(i,n){d[i]=i;b[i]=0;}}
	signed find(signed x){
		if(d[x]==x){
			return x;
		}else{
			return d[x]=find(d[x]);
		}
	}
	UnionFind(signed n){rep(i,n){d[i]=i;b[i]=0;}}
	void unite(signed x,signed y){
		x=find(x);
		y=find(y);
		if(x==y)return;
		if(b[x]<b[y]){
			d[x]=y;
		}else{
			d[y]=x;
			if(b[x]==b[y])b[x]++;
		}
	}
	bool same(signed x,signed y){return (find(x)==find(y));}
};
*/
ull s[51];
ull p[51];
ull now=0;
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	ull x;
	cin>>n>>x;
	s[0]=1;
	p[0]=1;
	ull mid;

	rep(i,1,51){s[i]=(2*s[i-1])+3;p[i]=(2*p[i-1])+1;}

	for( int i=n;i>=0;i--){
		if(x<=0)break;
//		if(i!=0&&x<=1)break;
		mid=s[i]/2+1;
		if(mid==x){now+=p[i-1]+1;break;}
		if(mid>x){x=x-1;}
		if(mid<x){x=x-s[i-1]-2;now=now+1+p[i-1];}
	}
	cout<<now<<endl;

	return 0;
}
