#include<stdio.h>
struct TT{int nu;int sco;int jun;};

int main(){

	struct TT TR[101]={};
int n,x;
int c=0;
while(1)
{
	scanf("%d,%d",&n,&x);if(n==0&&x==0)break;
	TR[c].nu=n;TR[c].sco=x;
	c++;
}
for(int i=0;i<c;i++)
	for(int j=c-1;j>i;j--)
		if(TR[j].sco>TR[j-1].sco){struct TT QQ=TR[j];TR[j]=TR[j-1];TR[j-1]=QQ;}

int cn=1;TR[0].jun=1;
for(int i=1;i<c;i++){

	
if(TR[i].sco!=TR[i-1].sco)cn++;
TR[i].jun=cn;

}

while(scanf("%d",&x)!=EOF){


for(int i=0;i<c;i++)
if(x==TR[i].nu)printf("%d\n",TR[i].jun);
}
return 0;
}