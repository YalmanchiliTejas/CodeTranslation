#include<bits/stdc++.h>
#define rep(i,n)for(int i=0;i<n;i++)
using namespace std;

int main(){
	int m;scanf("%d",&m);
	rep(i,m){
		int p,y,n;scanf("%d%d%d",&p,&y,&n);
		double Max=0;
		rep(j,n){
			int o,d;double k;
			scanf("%d%lf%d",&o,&k,&d);
			if(o){
				double x=p;
				rep(t,y){x*=(1+k);x=(int)x;x-=d;}
				Max=max(Max,x);
			}
			else{
				double r=p,cnt=0;
				rep(t,y){cnt+=r*k;cnt=(int)cnt;r=(int)r;r-=d;}
				Max=max(Max,r+cnt);
			}
		}
		printf("%d\n",(int)Max);
	}
}