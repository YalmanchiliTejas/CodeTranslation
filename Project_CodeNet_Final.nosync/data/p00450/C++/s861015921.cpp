#include<iostream>
#include<cstdio>
using namespace std;
int N;
int A[100000];
int B[100000];
int now=0;
int main()
{
	while(true){
		now=0;
		scanf("%d",&N);
		if(N==0)break;
		int col;
		scanf("%d",&col);
		A[0]=col;B[0]=1;
		for(int i=1;i<N;i++){
			scanf("%d",&col);
			if(i&1){
				if(A[now]==col)B[now]++;
				else{
					if(now==0){
						A[now]=col;B[now]++;
					}
					else{
						B[now-1]+=(B[now]+1);
						A[now]=0;B[now]=0;
						now--;
					}
				}
			}
			else{
				if(A[now]==col)B[now]++;
				else{
					now++;A[now]=col;B[now]=1;
				}
			}
		}
		int ans=0;
		for(int i=0;i<=now;i++){
			if(A[i]==0)ans+=B[i];
			A[i]=0;B[i]=0;
		}
		printf("%d\n",ans);
	}
}