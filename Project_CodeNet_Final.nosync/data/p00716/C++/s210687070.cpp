#include <cstdio>
#include <iostream>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int main(){
	int m;
	scanf("%d",&m);
	rep(tt,m){
		int money,y,n,mx=0;
		scanf("%d%d%d",&money,&y,&n);
		rep(i,n){
			int t,tesu;
			double ri;
			scanf("%d%lf%d",&t,&ri,&tesu);
			int now=money;
			if(t==0){
				int all=0;
				rep(j,y) all+=ri*now,now-=tesu;
				now+=all;
			}
			else rep(j,y) now=(ri+1)*now-tesu;
			mx=max(mx,now);
		}
		printf("%d\n",mx);
	}
}