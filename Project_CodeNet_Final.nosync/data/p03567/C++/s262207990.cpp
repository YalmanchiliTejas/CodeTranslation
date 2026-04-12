#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<deque>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<stdlib.h>
#include<cassert>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
const long long d2=500000004;
const double EPS=1e-6;
const double PI=acos(-1.0);
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
char in[10];
int main(){
	scanf("%s",in);
	for(int i=0;i<4;i++){
		if(in[i]=='A'&&in[i+1]=='C'){
			printf("Yes\n");return 0;
		}
	}
	printf("No\n");
}