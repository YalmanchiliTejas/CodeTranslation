#include<bits/stdc++.h>
#define mo 1000000007
#define pi 3.1415926535898
#define eps 1e-9 
using namespace std;
long long read(){
    long long xx=0,flagg=1;
    char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-')
        ch=getchar();
    if(ch=='-'){
        flagg=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        xx=xx*10+ch-'0';
        ch=getchar();
    }
    return xx*flagg;
}
void pus(long long xx,long long flagg){
    if(xx<0){
        putchar('-');
        xx=-xx;
    }
    if(xx>=10)
        pus(xx/10,0);
    putchar(xx%10+'0');
    if(flagg==1)
        putchar(' ');
    if(flagg==2)
        putchar('\n');
    return;
}
long long n,i,j,x[200005],y[200005],max1,min1,sum,book[200005],flag,ans,min2,max2,top;
struct nyh{
	long long x,id;
}o[400005];
bool cmp(nyh u,nyh v){
	return u.x<v.x;
}
int main(){
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	n=read();
	for(i=1;i<=n;i++){
		x[i]=read();
		y[i]=read();
	}
	for(i=1;i<=n;i++)
		if(x[i]>y[i])
			swap(x[i],y[i]);
	for(i=1;i<=n;i++)
		if(x[min1]>x[i]||min1==0)
			min1=i;
	for(i=1;i<=n;i++)
		if(y[max1]<y[i]||max1==0)
			max1=i;
	ans=1000000000000000000LL;
	if(max1!=min1){
		for(i=1;i<=n;i++){
			if(min1!=i){
				top++;
				o[top].x=x[i];
				o[top].id=i;
			}
			if(max1!=i){
				top++;
				o[top].x=y[i];
				o[top].id=i;
			}
		}
		sort(o+1,o+top+1,cmp);
		j=1;
		for(i=1;i<=top;i++){
			book[o[i].id]++;
			if(book[o[i].id]==1)
				sum++;
			while(sum==n){
				book[o[j].id]--;
				if(book[o[j].id]==0)
					sum--;
				flag=1;
				j++;
			}
			if(flag==1)
				ans=min(ans,(o[i].x-o[j-1].x)*(y[max1]-x[min1]));
		}
	}
			
	top=0;
	for(i=1;i<=n;i++)
		if(x[max2]<x[i]||max2==0)
			max2=i;
	for(i=1;i<=n;i++)
		if(y[min2]>y[i]||min2==0)
			min2=i;
	ans=min(ans,(x[max2]-x[min1])*(y[max1]-y[min2]));
	pus(ans,2);
	return 0;
}