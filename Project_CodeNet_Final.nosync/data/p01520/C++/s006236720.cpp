#include<bits/stdc++.h>
using namespace std;

int main(){
int a,b,c;
scanf("%d%d%d",&a,&b,&c);
for(int d=0;d<a;d++){
	int e;
	cin>>e;
	int f=b/e;
	f*=e;
	if(f>=b-c){printf("%d\n",d+1);return 0;}
	f+=e;;
	if(f<=b+c){printf("%d\n",d+1);return 0;}
}
printf("-1\n");
}