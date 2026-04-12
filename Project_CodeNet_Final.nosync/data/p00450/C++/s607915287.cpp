#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
#define F (110000)

int n,c[100000],d[300000],cnt;

int main(){
	while(scanf("%d",&n),n){
		for(int i=0;i<n;i++) scanf("%d",&c[i]);
		fill(d,d+300000,0);
		d[F]=1;
		cnt=F;
		for(int i=1;i<n;i++){
			if(c[i]!=c[i-1]) cnt++;
			d[cnt]++;
			if(i%2==1&&c[i]!=c[i-1]&&cnt>=2){
				cnt-=2;
				d[cnt]+=d[cnt+1]+d[cnt+2];
				d[cnt+1]=d[cnt+2]=0;
			}
		}
		int res=0;
		for(int i=cnt-c[n-1];i>=0;i-=2) res+=d[i];
		printf("%d\n",res);
	}
}