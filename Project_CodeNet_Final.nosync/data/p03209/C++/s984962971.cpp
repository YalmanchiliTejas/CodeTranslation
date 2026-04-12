#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <bitset>     //UWAGA - w czasie kompilacji musi byc znany rozmiar wektora - nie mozna go zmienic
#include <cassert>
#include <iomanip>        //do setprecision
#include <ctime>
#include <complex>
using namespace std;

#define FOR(i,b,e) for(int i=(b);i<(e);++i)
#define FORQ(i,b,e) for(int i=(b);i<=(e);++i)
#define FORD(i,b,e) for(int i=(b)-1;i>=(e);--i)
#define REP(x, n) for(int x = 0; x < (n); ++x)

#define ST first
#define ND second
#define PB push_back
#define MP make_pair
#define LL long long
#define ULL unsigned LL
#define LD long double

const double pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342;
const int mod=1000000007;
LL p[55];
LL all[55];

LL f(LL n,LL x){
	if(n==0){
		return 1;
	}else{
		if(x==1){
			return 0;
		}else if(x<=all[n-1]+1){
			return f(n-1,x-1);
		}else if(x==all[n-1]+2){
			return f(n-1,x-1)+1;
		}else if(x<=2*all[n-1]+2){
			return p[n-1]+1+f(n-1,x-(all[n-1]+2));
		}else{
			return p[n];
		}
	}
}

int main(){
 	LL n,x;
	cin>>n>>x;
	all[0]=p[0]=1;
	FOR(i,0,n){
		all[i+1]=2*all[i]+3;
		p[i+1]=2*p[i]+1;
	}
	cout<<f(n,x)<<endl;
    return 0;
}
