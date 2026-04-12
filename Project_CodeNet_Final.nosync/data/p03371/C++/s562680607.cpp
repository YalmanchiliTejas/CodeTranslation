#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int maxn=1e5;
int a,b,c,d,x,y;
int main(){
	cin>>a>>b>>c>>x>>y;
	if((a+b)>c*2){
	if(x>=y)d=2*c*y+a*(x-y);
	else d=2*c*x+b*(y-x);
	d=min(d,max(x,y)*c*2);
	}
	else d=a*x+b*y;
	printf("%d\n",d);
}


