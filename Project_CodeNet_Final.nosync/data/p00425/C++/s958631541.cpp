#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<string>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define reps(i,n) for(int i=1;i<=n;i++)

int main(){
	while(1){
		int n;
		cin>>n;
		if(n==0)break;
		
		int sai[7]={0};
		reps(i,6)sai[i]=i;
		
		int ans=1;
		rep(i,n){
			string a;
			cin>>a;
			int tm;
			if(a[0] == 'N'){
				tm=sai[1];
				sai[1]=sai[2];
				sai[2]=sai[6];
				sai[6]=sai[5];
				sai[5]=tm;
			}
			if(a[0] == 'S'){
				tm=sai[1];
				sai[1]=sai[5];
				sai[5]=sai[6];
				sai[6]=sai[2];
				sai[2]=tm;
			}
			if(a[0] == 'E'){
				tm=sai[1];
				sai[1]=sai[4];
				sai[4]=sai[6];
				sai[6]=sai[3];
				sai[3]=tm;
			}
			if(a[0] == 'W'){
				tm=sai[1];
				sai[1]=sai[3];
				sai[3]=sai[6];
				sai[6]=sai[4];
				sai[4]=tm;
			}
			if(a[0] == 'L'){
				tm=sai[2];
				sai[2]=sai[4];
				sai[4]=sai[5];
				sai[5]=sai[3];
				sai[3]=tm;
			}
			if(a[0] == 'R'){
				tm=sai[2];
				sai[2]=sai[3];
				sai[3]=sai[5];
				sai[5]=sai[4];
				sai[4]=tm;
			}
			ans+=sai[1];
		}
		
		printf("%d\n",ans);
	}
}