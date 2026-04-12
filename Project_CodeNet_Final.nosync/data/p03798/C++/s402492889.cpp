#include<bits/stdc++.h>
using namespace std;
char str[100010];
int n;
int o[100010];
int shee[100010];
int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	scanf("%d",&n);
	scanf("%s",str);
	for(int i=0;i<n;i++){
		o[i+1]=(str[i]!='o');
	}
	o[n+1]=o[1];
	for(int mask=0;mask<8;mask++){
		shee[0]=((mask)&1);
		shee[1]=((mask>>1)&1);
		shee[2]=((mask>>2)&1);
		for(int j=2;j<=n+1;j++){
			shee[j+1]=(shee[j-2]^o[j]);
		}
		if(shee[0]^shee[n]^shee[1]^shee[n+1]||shee[1]^shee[n+1]^shee[2]^shee[n+2])
			continue;
		for(int i=1;i<=n;i++)
			cout<<((shee[i]^shee[i-1])?'W':'S');
		return 0;
	}
	cout<<-1;
	return 0;
}
