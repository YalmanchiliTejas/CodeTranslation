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

const int ST_MAX = (1 << 20);

template <class T , class U> class ST{
	T x[ST_MAX * 2];
	U lazy[ST_MAX * 2];
	
	T eval(T a , T b){
		return max(a,b);
	}
	
	U syn(U a , U b){
		return a+b;
	}
	
	void work(int a){
		if(a < ST_MAX){
			lazy[a * 2] = syn(lazy[a] , lazy[a * 2]);
			lazy[a * 2 + 1] = syn(lazy[a] , lazy[a * 2 + 1]);
		}
		x[a] += lazy[a];
		lazy[a] = 0;
	}
	
	void ren(int a , int b , int e , int s , int f , U z){
		if(e <= s || f <= b){
			work(a);
			return;
		}
		if(s <= b && e <= f){
			lazy[a] = syn(lazy[a] , z);
			work(a);
			return;
		}
		work(a);
		ren(2 * a , b , (b + e) / 2 , s , f , z);
		ren(2 * a + 1 , (b + e) / 2 , e , s , f , z);
		x[a] = eval(x[a * 2] , x[a * 2 + 1]);
	}
	
	T read_ST(int a , int b , int e , int s , int f){
		work(a);
		if(e <= s || f <= b) return 0;
		if(s <= b && e <= f) return x[a];
		return eval(read_ST(2 * a , b , (b + e) / 2 , s , f) , read_ST(2 * a + 1 , (b + e) / 2 , e , s , f));
	}
	
public:
	
	ST(){
		fill(x,x+ST_MAX*2,0);
		fill(lazy,lazy+ST_MAX*2,0);
	}
	
	void put(int s , int f , U b){
		ren(1 , 0 , ST_MAX , s , f , b);
	}
	
	T get(int s , int f){
		return read_ST(1 , 0 , ST_MAX , s , f);
	}
};

ST<LL,LL> solve;

int main(){
	int N,M; cin >> N >> M;
	vector<int> l(M),r(M),s(M);
	vector<LL> a(M);
	repp(i,0,M){
		cin >> l[i] >> r[i] >> a[i];
		s[i] = i;
	}
	sort(s.begin(),s.end(),[&](const int &x, const int &y){return r[x] < r[y];});
	int k = 0;
	repp(i,1,N+1){
		while(k < M && r[s[k]] == i){
			solve.put(l[s[k]],r[s[k]]+1,a[s[k]]);
			++k;
		}
		solve.put(i+1,i+2,solve.get(0,i+1));
	}
	cout << solve.get(0,N+1) << endl;
	return 0;
}
