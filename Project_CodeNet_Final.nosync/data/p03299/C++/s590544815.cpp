#include<bits/stdc++.h>
#define P pair<int,int>
#define fir first
#define sec second
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
const int N=105;
int a[N],n;
int ksm(int x,int y)
{
	int res=1;
	while (y){if (y&1) res=(ll)res*x%mod;x=(ll)x*x%mod;y>>=1;}
	return res;
}
void up(int &x,int y){x=x-mod+y;x=(x<0)?x+mod:x;}
P dfs(int l,int r,int h)//笛卡尔树,s1表示存在相同相邻，s2表示010101相邻不同 
{
	int Min=inf,cnt=0;
	for (int i=l;i<=r;i++) Min=min(Min,a[i]);
	for (int i=l;i<=r;i++) if (Min==a[i]) cnt++;
	if (cnt==r-l+1)//边界，矩形 
	  return P(((ll)ksm(2,r-l+1)-2+mod)%mod,ksm(2,Min-h));
	int s1=1,s2=1,blo=0;cnt=0;
    for (int i=l,L=l,R=l-1;i<=r;i++)
    {
    	if (a[i]!=Min) R=i;else cnt++;
    	if (a[i]==Min||i==r)
    	{
    		if (L<=R)
    		{
    		  blo++; 
    		  P now=dfs(L,R,Min);
			  s1=(ll)s1*(now.fir+(ll)now.sec*2%mod)%mod;//全集 
			  s2=(ll)s2*now.sec%mod;//01交替 
			}
    		L=i+1,R=i;
		}
	}
	s1=((ll)s1-(ll)s2*ksm(2,blo)%mod+mod)%mod;//存在相同相邻 
	P ans;
	ans.fir=(ll)s1*ksm(2,cnt)%mod;
	ans.fir=((ll)ans.fir+((ll)ksm(2,cnt)*ksm(2,blo)%mod-2+mod)%mod*s2%mod)%mod; 
	ans.sec=(ll)s2*ksm(2,Min-h)%mod;
	return ans;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	P now=dfs(1,n,0);//[1,n]当前底层高度 
	printf("%d\n",((ll)now.fir+now.sec)%mod);
	return 0;
}