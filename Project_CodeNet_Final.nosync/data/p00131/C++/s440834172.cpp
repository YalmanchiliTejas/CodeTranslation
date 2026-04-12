#include <iostream>
#include <stdio.h>
#include <utility>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int dx[]={-1,0,0,1};
int dy[]={0,0,-1,0};
int main()
{
    int n;
	cin>>n;
	bool fir=true;
	while(n--){
		//if(!fir)cout<<endl;
		int panel[10]={};
		for(int i=0;i<10;i++){
			for(int j=0;j<10;j++){
				int tmp;
				cin>>tmp;
				panel[i]|=tmp<<j;
			}
		}
		for(int i=0;i<(1<<10);i++){//1??????ans?????????
			int ans[10]={};
			ans[0]=i;
			for(int j=0;j<9;j++){//????????????ans????¨????
				for(int k=0;k<10;k++){//?????????????????°???
					int tmp=0;
					for(int l=0;l<4;l++){
						int nx=k+dx[l],ny=j+dy[l];
						if(0<=nx&&nx<10&&0<=ny&&ny<9)tmp+=(ans[ny]>>nx)&1;
					}
					if((tmp+(panel[j]>>k)&1)%2)ans[j+1]|=1<<k;
				}
			}
			int check=ans[8];
			for(int j=0;j<10;j++){
				if((ans[9]>>j)&1){
					for(int k=-1;k<=1;k++){
						int x=j+k;
						if(0<=x&&x<10){
							if((check>>x)&1)check&=~(1<<x);
							else check|=1<<x;
						}
					}
				}
			}
			if(check==panel[9]){
				for(int y=0;y<10;y++){
					for(int x=0;x<10;x++){
						int tmp=(ans[y]>>x)&1;
						printf(x==9?"%d\n":"%d ",tmp);
					}
				}		
				break;
			}
		}
		fir=false;
	}
    return 0;
}