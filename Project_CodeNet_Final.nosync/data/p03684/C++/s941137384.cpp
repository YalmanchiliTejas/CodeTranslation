#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int , int> P2;
typedef pair<pair<int , int> , int> P3;
typedef pair<pair<int , int> , pair<int , int> > P4;
#define PB(a) push_back(a)
#define MP(a , b) make_pair((a) , (b))
#define M3P(a , b , c) make_pair(make_pair((a) , (b)) , (c))
#define M4P(a , b , c , d) make_pair(make_pair((a) , (b)) , make_pair((c) , (d)))
#define repp(i,a,b) for(int i = (int)(a) ; i < (int)(b) ; ++i)
#define repm(i,a,b) for(int i = (int)(a) ; i > (int)(b) ; --i)

const int UF_MAX = 1000000;

class UF{
	int x[UF_MAX];
	int co;
	
public:
	
	UF(){
		fill(x,x+UF_MAX,-1);
		co = 0;
	}
	
	int boss(int a){
		int s = a;
		while(x[s] > -1) s = x[s];
		if(s != a) x[a] = s;
		return s;
	}
	
	void uni(int a , int b){
		int s = boss(a);
		int t = boss(b);
		if(s != t){
			++co;
			if(x[s] < x[t]){
				x[s] += x[t];
				x[t] = s;
			} else {
				x[t] += x[s];
				x[s] = t;
			}
		}
	}
	
	bool find(int a , int b){
		return boss(a) == boss(b);
	}
	
	int count(){
		return co;
	}
	
	int member(int a){
		return -x[boss(a)];
	}
}uf;

const int MC = 100010;
int N;
int x[MC],y[MC];
int a[MC],b[MC];
vector<P3> V;

int main(){
	scanf("%d" , &N);
	repp(i,0,N){
		scanf("%d%d" , x + i , y + i);
		a[i] = b[i] = i;
	}
	sort(a,a+N,[&](const int p , const int q){return x[p] < x[q];});
	sort(b,b+N,[&](const int p , const int q){return y[p] < y[q];});
	repp(i,1,N){
		V.PB(M3P(x[a[i]]-x[a[i-1]],a[i],a[i-1]));
		V.PB(M3P(y[b[i]]-y[b[i-1]],b[i],b[i-1]));
	}
	sort(V.begin(),V.end());
	LL ans = 0;
	for(auto z : V){
		if(uf.find(z.first.second,z.second)) continue;
		uf.uni(z.first.second,z.second);
		ans += z.first.first;
	}
	printf("%lld\n" , ans);
	return 0;
}
