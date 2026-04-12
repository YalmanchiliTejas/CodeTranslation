#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	while(true){
		int n;
		int a[50010][2];
		for(int i=0;i<50010;i++)a[i][0]=a[i][1]=0;
		scanf("%d",&n);
		if(n==0)return 0;
		int x;
		int y=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&x);
			if(i%2!=0){
				if(a[y][x]!=0){
					a[y][x]++;
				}
				else{
					y++;
					a[y][x]++;
				}
			}
			else{
				if(a[y][x]!=0)a[y][x]++;
				else{
					a[y][(x+1)%2]++;
					swap(a[y][0],a[y][1]);
					if(y!=0){
						a[y-1][x%2]+=a[y][x%2];
						a[y][x]=0;
						y--;
					}
				}
			}
		}
		int ans=0;
		/*
		int z=0;
		while(z<=10){
			printf("%d %d\n",a[z][0],a[z][1]);
			z++;
		}
		*/
		for(int i=0;i<50000;i++)ans+=a[i][0];
		printf("%d\n",ans);

	}
}