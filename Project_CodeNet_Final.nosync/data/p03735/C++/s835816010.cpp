//Night's template
//orzakyrt
#include <iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#define R register
#define LL long long
#ifdef __DEBUG__
	#define Debug (fprintf(stderr,"orzyrt\n"),fflush(stderr))
	#define debug(__a...) (fprintf(stderr,__a),fflush(stderr))
	#define setfile(__a) ('orzyrt')
	#define Compile(__a) system("g++ "__a".cpp -lm -o "__a)
#else
	#define Debug ('orzyrt')
	#define debug(__a...) ('orzyrt')
	#define setfile(__a) freopen(__a".in","r",stdin);freopen(__a".out","w",stdout)
	#define Compile(__a) ('orzyrt')
#endif
template<class TT>inline TT Max(R TT a,R TT b){return a<b?b:a;}
template<class TT>inline TT Min(R TT a,R TT b){return a<b?a:b;}
template<class TT>inline TT Abs(R TT a){return a<0?-a:a;}
template<class TT>inline TT cmin(R TT &a,R TT b){(b<a)&&(a=b);}
template<class TT>inline TT cmax(R TT &a,R TT b){(a<b)&&(a=b);}
using namespace std;
template<class TT>inline void read(R TT &x){
	x=0;R bool f=false;R char c=getchar();
	for(;c<48||c>57;c=getchar())f|=(c=='-');
	for(;c>47&&c<58;c=getchar())x=(x<<1)+(x<<3)+(c^48);
	(f)&&(x=-x);
}
//end template
 
namespace Night{
	const int maxn = 200010;
	const int inf = 2147483647;
	int n;
	int min1=inf,min2=inf,max1=-inf,max2=-inf;
	LL ans=1ll<<60;
	multiset<int>a,b;
	struct node{
		int x,y;
		node(){}
		node(R int x,R int y):x(x),y(y){}
		inline bool operator < (R const node &_)const{
			return x<_.x;
		}
	};
	vector<node>v;
	int main(){
		read(n);
		for(R int i=1,xx,yy,x,y;i<=n;++i){
			read(xx);read(yy);
			x=Min(xx,yy);y=Max(xx,yy);
			v.push_back(node(x,y));
			a.insert(x);b.insert(y);
		}
		sort(v.begin(),v.end());
		for(R vector<node>::iterator i=v.begin();i!=v.end();++i){
			a.erase(a.find(i->x));b.erase(b.find(i->y));
			b.insert(i->x);a.insert(i->y);
			cmin(ans,1ll*(*a.rbegin()-*a.begin())*(*b.rbegin()-*b.begin()));
		}
		for(R vector<node>::iterator i=v.begin();i!=v.end();++i){
			cmin(min1,i->x);
			cmin(min2,i->y);
			cmax(max1,i->x);
			cmax(max2,i->y);
		}
		cmin(ans,1ll*(max1-min1)*(max2-min2));
		cout<<ans;
		return 0;
	}
}
int main(){
	return Night::main();
}