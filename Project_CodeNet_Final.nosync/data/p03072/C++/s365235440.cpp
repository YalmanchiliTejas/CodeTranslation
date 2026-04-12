#ifdef _WIN32
#define DEBUG	1
#endif

#define _CRT_SECURE_NO_WARNINGS
#define MATH_PI 3.14159265358979323846264338327950288419716939
#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

#ifdef DEBUG
#include "include.h"
#else
inline void wait(){}
inline void dout(const char *arg, ...){}
#endif

template<typename T>inline void swap(T a, T b){T t = a; a = b; b = t;}

#define CLIP(ptr, min, max) {if((min)<=(max)){if(ptr<(min)){ptr=(min);}if(ptr>(max)){ptr=(max);}}}
#define max(a, b) a > b ? a : b;
#define min(a, b) a > b ? b : a;
#define Sin(deg) sin((deg)*MATH_PI/180)
#define Cos(deg) cos((deg)*MATH_PI/180)
#define Tan(deg) tan((deg)*MATH_PI/180)
#define Rad(deg) ((deg)*MATH_PI/180)
#define ff(param, num) for(int param=0 ; param<num ; ++param)
#define fi(num) for(int i=0 ; i<num ; ++i)
#define fj(num) for(int j=0 ; j<num ; ++j)
#define fk(num) for(int k=0 ; k<num ; ++k)
#define fl(num) for(int l=0 ; l<num ; ++l)
#define ffr(param, num) for(int param=num-1 ; param>=0 ; --param)
#define fir(num) for(int i=num-1 ; i>=0 ; --i)
#define fjr(num) for(int j=num-1 ; j>=0 ; --j)
#define fkr(num) for(int k=num-1 ; k>=0 ; --k)
#define flr(num) for(int l=num-1 ; l>=0 ; --l)
#define gi(p) Scanf("%d", p)
#define gi2(p1, p2) Scanf2("%d %d", p1, p2)
#define gi3(p1, p2, p3) Scanf3("%d %d %d", p1, p2, p3)
#define gi4(p1, p2, p3, p4) Scanf4("%d %d %d %d", p1, p2, p3, p4)
#define gll(p) Scanf("%lld", p)
#define gll2(p1, p2) Scanf2("%lld %lld", p1, p2)
#define gll3(p1, p2, p3) Scanf3("%lld %lld %lld", p1, p2, p3)
#define gll4(p1, p2, p3, p4) Scanf4("%lld %lld %lld %lld", p1, p2, p3, p4)
#define gf(p) Scanf("%f", p)
#define gf2(p1, p2) Scanf2("%f %f", p1, p2)
#define gf3(p1, p2, p3) Scanf3("%f %f %f", p1, p2, p3)
#define gf4(p1, p2, p3, p4) Scanf4("%f %f %f %f", p1, p2, p3, p4)
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
signed main() {

	int ii, jj, kk, ll;
	int N;
	int ret = 0;
	int flag = 0;
	char cbuf[8192];

	int h[100];
	gi(N);
	fi(N){
		gi(h[i]);
	}

	fi(N){
		flag = 0;
		fj(i){
			if(h[i] < h[j]){
				flag = 1;
				break;
			}
		}
		if(!flag) ret++;
	}

	ans(ret);

	wait();

	return 0;
}