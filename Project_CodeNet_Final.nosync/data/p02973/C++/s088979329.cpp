#include <bits/stdc++.h>
#define ff(x,a,b) for(int x=a;x<=b;++x)
#define fff(x,a,b) for(int x=a;x>=b;--x)
using namespace std;
typedef long long ll;
void rd(int &v){char ch;for(ch='*';ch<'0'||ch>'9';ch=getchar());for(v=0;ch>='0'&&ch<='9';ch=getchar()) v=v*10+ch-'0';}
int n,dl[100005],len,a[100005];
int main()
{
	cin>>n;
	ff(i,1,n) rd(a[i]);
	len=1;dl[1]=a[n];
	fff(i,n-1,1)
	{
		int k=upper_bound(dl+1,dl+1+len,a[i])-dl;
		if(k>len) dl[++len]=a[i];
		if(dl[k]>a[i]) dl[k]=a[i];
	}
	cout<<len;
}