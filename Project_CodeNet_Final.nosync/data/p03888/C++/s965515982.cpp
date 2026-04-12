#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for(int i = (l);i < (r);i++)
#define ALL(x) (x).begin(),(x).end()
template<typename T> bool chmax(T& a,const T& b){return a < b ? (a = b,true) : false;}
template<typename T> bool chmin(T& a,const T& b){return b < a ? (a = b,true) : false;}
typedef long long ll;

double R1,R2;

double f(double m)
{
	return 1.0 / m;
}

int main()
{
	scanf("%lf%lf",&R1,&R2);

	double lo = 0.1,hi = 100.0,mid;
	FOR(i,0,100){
		mid = (lo + hi) / 2.0;
		if(f(mid) >= 1.0 / R1 + 1.0 / R2){
			lo = mid;
		}
		else{
			hi = mid;
		}
	}

	printf("%.10f\n",(lo + hi) / 2.0);

	return 0;
}
