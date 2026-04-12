#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<deque>
#include<stack>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<stdlib.h>
#include<cassert>
#include<time.h>
#include<bitset>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
const long long d2=(mod+1)/2;
const long double EPS=1e-13;
const long double PI=acos(-1.0);
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
long double ABS(long double a){return max(a,-a);}
int c[700];
long long f[700];
long long C[700][10];
int main(){
	long long a;scanf("%lld",&a);
	C[0][0]=1;
	for(int i=0;i<650;i++){
		for(int j=0;j<9;j++){
			C[i+1][j]+=C[i][j];
			C[i+1][j+1]+=C[i][j];
		}
	}
	for(int i=0;i<600;i++){
		f[i]=C[i+7][7];
	}
	for(int i=599;i>=0;i--){
		c[i]=a/f[i];
		a%=f[i];
	}
	for(int i=0;i<600;i++){
		printf("FESTIVA");
		for(int j=0;j<c[i];j++)printf("L");
	}
	printf("\n");
}