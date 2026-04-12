#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=100+10;
int a[maxn][maxn];
int main(){
	int h,w;
	scanf("%d%d",&h,&w);
	for(int i=0;i<h;i++){
		char s[105];
		scanf("%s",s);
		for(int j=0;j<strlen(s);j++)
		   if(s[j]=='#')a[i][j]=1;
		   else a[i][j]=0;
	}
	for(int i=0;i<h;i++){
		bool flag=true;
	    for(int j=0;j<w;j++){
	    	if(a[i][j]==1)flag=false;
		}	
		if(flag)for(int j=0;j<w;j++)
		           a[i][j]=2;
	}
	for(int i=0;i<w;i++){
		bool flag=true;
	    for(int j=0;j<h;j++){
	    	if(a[j][i]==1)flag=false;
		}	
		if(flag)for(int j=0;j<h;j++)
		           a[j][i]=2;
	}
	for(int i=0;i<h;i++){
		bool flag=false;
		 for(int j=0;j<w;j++)
		    if(a[i][j]==1)printf("#"),flag=true;
		    else if(a[i][j]==0)printf("."),flag=true;
		if(flag)printf("\n");    
	}
	return 0;
}