#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <climits>
using namespace std;

#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define EPS 1e-8
#define DEB 0


int main(){
	int m,sikin,year,n,type,tesuu,ans;
	double ritu;
	scanf("%d",&m);
	while(m--){
		ans = 0;
		scanf("%d%d%d",&sikin,&year,&n);
		rep(i,n){
			scanf("%d%lf%d",&type,&ritu,&tesuu);
#if DEB			
			printf("%d %lf %d\n",type,ritu,tesuu);
#endif
			int init = sikin;
			if( type==0 ){ //tanri
				int sum = 0;
				rep(j,year){
					double risi = (double)init * ritu;
					init = init - tesuu;
					sum += (int)floor(risi);
#if DEB					
					printf("init:%d  , sum:%d\n",init,sum);
#endif					
				}
				ans = max(ans, sum+init);
			}else{ // hukuri
				rep(j,year){
					double risi = (double)init * ritu;
					init = init + (int)floor(risi) - tesuu;
#if DEB
					printf("init:%d\n",init);
#endif					
				}
				ans = max(ans, init);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}