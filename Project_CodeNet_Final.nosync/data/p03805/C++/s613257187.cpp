#define _CRT_SECURE_NO_WARNINGS
#define MATH_PI 3.14159265358979323846264338327950288419716939
#define DIVIDER9 1000000007
#define lli long long int
#include <iostream>
#include <string.h>
#include <fstream>
#include <math.h>
using namespace std;

#ifdef _WIN32
#pragma warning(disable : 4101)


signed wait(){
	char wait_dummy[256];
	scanf("%c", &wait_dummy);
	return 0;
}


template <typename ... Args>
void dout(const char *format, Args const & ... args){
	printf(format, args ...);
}

#define MAX_CHARBUF	65536
#define DATAFILE "data.dat"

class csLocalInput{
	int FileOpen();
public:
	FILE *fp;
	csLocalInput();
};


csLocalInput::csLocalInput() {
	FileOpen();
}

int csLocalInput::FileOpen() {
	fp = fopen(DATAFILE, "rt");
	return 1;
}

csLocalInput local_in;


#define DEBUG	1
#else
inline signed wait() { return 0; }
inline void dout(const char *arg, ...) {}
#endif

template<typename T>inline void SWAP(T &a, T &b) { T t = a; a = b; b = t; }
inline void CSWAP(char *&a, char *&b) { char *t = a; a = b; b = t; }

#define CLIP(ptr, min, max) {if((min)<=(max)){if(ptr<(min)){ptr=(min);}if(ptr>(max)){ptr=(max);}}}


#define Sin(deg) sin((deg)*MATH_PI/180.0)
#define Cos(deg) cos((deg)*MATH_PI/180.0)
#define Tan(deg) tan((deg)*MATH_PI/180.0)
#define Rad(deg) ((deg)*MATH_PI/180.0)
#define rep(param, num) for(int param=0 ; param<num ; ++param)
#define fi(num) for(int i=0 ; i<num ; ++i)
#define fj(num) for(int j=0 ; j<num ; ++j)
#define fk(num) for(int k=0 ; k<num ; ++k)
#define fl(num) for(int l=0 ; l<num ; ++l)
#define fn(num) for(int n=0 ; n<num ; ++n)
#define ffr(param, num) for(int param=num-1 ; param>=0 ; --param)
#define fir(num) for(int i=num-1 ; i>=0 ; --i)
#define fjr(num) for(int j=num-1 ; j>=0 ; --j)
#define fkr(num) for(int k=num-1 ; k>=0 ; --k)
#define flr(num) for(int l=num-1 ; l>=0 ; --l)
#define fnr(num) for(int n=num-1 ; n>=0 ; --n)
#define gi(p) int p; ud_gi(p)
#define gi2(p1, p2) int p1, p2; ud_gi2(p1, p2)
#define gi3(p1, p2, p3) int p1, p2, p3; ud_gi3(p1, p2, p3)
#define gi4(p1, p2, p3, p4) int p1, p2, p3, p4; ud_gi4(p1, p2, p3, p4)
#define glli(p) lli p; ud_glli(p)
#define glli2(p1, p2) lli p1, p2; ud_glli2(p1, p2)
#define glli3(p1, p2, p3) lli p1, p2, p3; ud_glli3(p1, p2, p3)
#define glli4(p1, p2, p3, p4) lli p1, p2, p3, p4; ud_glli4(p1, p2, p3, p4)
#define gf(p) double p; ud_gf(p);
#define gf2(p1, p2) double p1, p2; ud_gf2(p1, p2);
#define gf3(p1, p2, p3) double p1, p2, p3; ud_gf3(p1, p2, p3);
#define gf4(p1, p2, p3, p4) double p1, p2, p3, p4; ud_gf4(p1, p2, p3, p4);

#define ud_gi(p) Scanf("%d", p)
#define ud_gi2(p1, p2) Scanf2("%d %d", p1, p2)
#define ud_gi3(p1, p2, p3) Scanf3("%d %d %d", p1, p2, p3)
#define ud_gi4(p1, p2, p3, p4) Scanf4("%d %d %d %d", p1, p2, p3, p4)
#define ud_glli(p) Scanf("%lld", p)
#define ud_glli2(p1, p2) Scanf2("%lld %lld", p1, p2)
#define ud_glli3(p1, p2, p3) Scanf3("%lld %lld %lld", p1, p2, p3)
#define ud_glli4(p1, p2, p3, p4) Scanf4("%lld %lld %lld %lld", p1, p2, p3, p4)
#define ud_gf(p) Scanf("%f", p)
#define ud_gf2(p1, p2) Scanf2("%f %f", p1, p2)
#define ud_gf3(p1, p2, p3) Scanf3("%f %f %f", p1, p2, p3)
#define ud_gf4(p1, p2, p3, p4) Scanf4("%f %f %f %f", p1, p2, p3, p4)

#ifdef DEBUG
#define gc(buf) fscanf(local_in.fp, "%s", buf)
#define Scanf(expr, p) fscanf(local_in.fp, expr, &p)
#define Scanf2(expr, p1, p2) fscanf(local_in.fp, expr, &p1, &p2)
#define Scanf3(expr, p1, p2, p3) fscanf(local_in.fp, expr, &p1, &p2, &p3)
#define Scanf4(expr, p1, p2, p3, p4) fscanf(local_in.fp, expr, &p1, &p2, &p3, &p4)
#else
#define gc(buf) Scanf("%s", buf)
#define Scanf(expr, p) scanf(expr, &p)
#define Scanf2(expr, p1, p2) scanf(expr, &p1, &p2)
#define Scanf3(expr, p1, p2, p3) scanf(expr, &p1, &p2, &p3)
#define Scanf4(expr, p1, p2, p3, p4) scanf(expr, &p1, &p2, &p3, &p4)
#endif
#define ans(p) cout << p << endl;
#define ans_end(p) cout << p << endl; return wait();
void CombSort(int N, int *ar, int order_ascending = 1) { int h = int(N / 1.3); int flag; int i; while (true) { flag = 0; for (i = 0; i + h < N; ++i) { if ((order_ascending&&ar[i] > ar[i + h]) || (!order_ascending&&ar[i] < ar[i + h])) { swap<int>(ar[i], ar[i + h]); flag = 1; } }if (h == 1 && !flag)break; if (h == 9 || h == 10) h = 11; if (h > 1)h = int(h / 1.3); } }
void CombSort(int N, lli *ar, int order_ascending = 1) { int h = int(N / 1.3); int flag; int i; while (true) { flag = 0; for (i = 0; i + h < N; ++i) { if ((order_ascending&&ar[i] > ar[i + h]) || (!order_ascending&&ar[i] < ar[i + h])) { swap<lli>(ar[i], ar[i + h]); flag = 1; } }if (h == 1 && !flag)break; if (h == 9 || h == 10) h = 11; if (h > 1)h = int(h / 1.3); } }

int EuclideanAlgorithm(int N, int *ar){
	fn(N - 1){
		while (true){ 
			if (ar[n] % ar[n + 1] == 0 || ar[n + 1] % ar[n] == 0) {
				ar[n + 1] = ar[n] < ar[n + 1] ? ar[n] : ar[n + 1];
				break; 
			}
			if (ar[n] > ar[n + 1]) {
				ar[n] %= ar[n + 1];
			} 
			else { 
				ar[n + 1] %= ar[n]; 
			} 
		} 
	}
	return ar[N - 1];
}

template<typename T>void CombSort(int N, T *ar, int order_ascending = 1) {
	int i, flag;
	int h = int(N / 1.3);
	while (true) {
		flag = 0;
		for (i = 0; i + h < N; ++i) {
			if (
				order_ascending && ar[i].SortValue > ar[i + h].SortValue ||
				!order_ascending && ar[i].SortValue < ar[i + h].SortValue
				) {
				swap<T>(ar[i], ar[i + h]);
				flag = 1;
			}
		}
		if (h > 1) {
			h = int(h / 1.3);
			if (h == 9 || h == 10) h = 11;
		}
		else {
			if (!flag) break;
		}
	}
}
#include <vector>
#include <algorithm>

struct UnionFind {
	vector<int> par; 

	UnionFind(int N) : par(N) { 
		for (int i = 0; i < N; i++) par[i] = i;
	}

	int root(int x) { 
		if (par[x] == x) return x;
		return par[x] = root(par[x]);
	}

	void unite(int x, int y) { 
		int rx = root(x); 
		int ry = root(y); 
		if (rx == ry) return; 
		par[rx] = ry; 
	}

	bool same(int x, int y) { 
		int rx = root(x);
		int ry = root(y);
		return rx == ry;
	}
};


void Replace(char *c, int len, char before, char after) {
	fi(len){
		if(c[i] == before) c[i] = after;
	}
}
void Replace(char *c, char before, char after){
	int len = strlen(c);
	Replace(c, len, before, after);
}

class csNode{
public:
	csNode(){
	}

};

class csStack{
public:
	csStack(){
		num = 0;
	}
	void alloc(int size){
		param = new int[size];
	}
	void sort(int order = 1){
		if(num > 1) CombSort(num, param, order);
	}

	int num;
	int *param;

	void push(int p){
		param[num++] = p;
	}
};

char s[200010];

csStack path[8];

class csOp{
public:
	csOp(){

	}

	int visited[8] = {0};
};

int cnt = 0;
int n, m;

void visit(int tgt, csOp op){
	op.visited[tgt] = 1;

	int flag = 1;
	fi(n){
		if(!op.visited[i]){
			flag = 0;
			break;
		}
	}
	if(flag){
		cnt++;
		return;
	}

	int nx;
	fi(path[tgt].num){
		nx = path[tgt].param[i];
		if(!op.visited[nx]){
			
			visit(nx, op);
		}
	}
}

signed main() {

	fi(8) path[i].alloc(8);
	
	ud_gi2(n, m);

	
	int u, v;
	fi(m){
		ud_gi2(u, v);
		--u; --v;
		path[u].push(v);
		path[v].push(u);
	}

	fi(m){
		path[i].sort();
	}

	csOp op;
	op.visited[0] = 1;

	fi(path[0].num){
		
		visit(path[0].param[i], op);
	}

	ans(cnt);

	return wait();
}
