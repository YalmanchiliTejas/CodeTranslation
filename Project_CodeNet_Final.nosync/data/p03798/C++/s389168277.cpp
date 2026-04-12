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
#include<bitset>
#include<stdlib.h>
#include<cassert>
#include<time.h>
#include<bitset>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
const long long d2=(mod+1)/2;
const double EPS=1e-6;
const double PI=acos(-1.0);
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
char in[110000];
int q[110000]; // 1: tozan 0: beau
int main(){
	int a;scanf("%d%s",&a,in);
	for(int i=0;i<2;i++)for(int j=0;j<2;j++){
		q[0]=i;q[1]=j;
		for(int k=2;k<a;k++){
			int s=(in[k-1]=='o');
			int t=q[k-1];
			if(s^t){
				q[k]=q[k-2];
			}else{
				q[k]=!q[k-2];
			}
		}
		bool ok=true;
		for(int k=0;k<a;k++){
			int s=(in[k]=='o');
			int t=q[k];
			if(s^t){
				if(q[(k+a-1)%a]!=q[(k+1)%a])ok=false;
			}else{
				if(q[(k+a-1)%a]==q[(k+1)%a])ok=false;
			}
		}
		if(ok){
			for(int k=0;k<a;k++){
				if(!q[k])printf("S");
				else printf("W");
			}
			printf("\n");return 0;
		}
	}
	printf("-1\n");
}