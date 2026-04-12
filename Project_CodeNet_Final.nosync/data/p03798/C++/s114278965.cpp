#include<cstdio>
#include<iostream>
using namespace std;
const int MR=100010;


char a[MR];
char ans[MR];
bool check(int a1,int a2,int n){
	a[0]='S'+a1*('W'-'S');a[1]='S'+a2*('W'-'S');
	for(int i=1;i<=n;i++){
		if((a[i]=='S' && ans[i]=='o')||(a[i]=='W' && ans[i]=='x')) a[i+1]=a[i-1];
		if((a[i]=='S' && ans[i]=='x')||(a[i]=='W' && ans[i]=='o')) a[i+1]='S'+'W'-a[i-1];
	}
	if(a[n]==a[0] && a[n+1]==a[1]){
		a[n]=0;
		return true;
	}
	else return false;
	
}

int main(){
	int n;
	scanf("%d",&n);
	cin.getline(ans,n+1);
	cin.getline(ans,n+1);
	ans[n]=ans[0];
	int a1,a2;
	bool ok=false;
	for(a1=0;a1<2;a1++){
		for(a2=0;a2<2;a2++){
			if(check(a1,a2,n)){
				ok=true;
				break;
			}
		}
		if(ok)break;
	}
	if(ok)printf("%s\n",a);
	else printf("-1\n");
	return 0;
}