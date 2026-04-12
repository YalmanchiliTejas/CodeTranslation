#include<cstdio>
void swap(int &x,int &y) {int t=x;x=y;y=t;}
int min(int x,int y) {return x<y?x:y;}
int main()
{
	int a,b,c,x,y;scanf("%d%d%d%d%d",&a,&b,&c,&x,&y);
	if(x>y) {swap(x,y);swap(a,b);}
	int ans=min(2*c*x,a*x+b*x)+min(2*c*(y-x),b*(y-x));
	printf("%d\n",ans);
	return 0;
}