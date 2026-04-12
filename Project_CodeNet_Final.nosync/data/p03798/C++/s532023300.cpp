#include<bits/stdc++.h>
using namespace std;

int zz[100005],n;
char dat[100005];

bool check(){
	if(!((dat[0]=='x')==zz[1]^zz[n-1]^zz[0])) return false;
	if(!((dat[n-1]=='x')==zz[n-2]^zz[n-1]^zz[0])) return false;
	return true;
}

int main(){
	scanf("%d%s",&n,dat);
	
	dat[0];
	
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			zz[1]=i;
			zz[0]=j;
			for(int k=1;k<n-1;k++)
				zz[k+1]=zz[k-1]^zz[k]^(dat[k]=='x');
			if(check()){
				for(int k=0;k<n;k++) printf("%c",zz[k]?'W':'S');
				return 0;
			}
		}
	}
	
	printf("-1\n");
	return 0;
} 