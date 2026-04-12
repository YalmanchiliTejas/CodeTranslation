#pragma GCC optimize (3)
#include<bits/stdc++.h>
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ff(v,a,b) for(int v=a;v<=b;v++)
#define fr(v,a,b) for(int v=a;v>=b;v--)
#define clr(a,v) memset(a,v,sizeof(a))
#define rep(v,a,b) for(int v=(a);(v)<(b);v++)
#define ll long long
using namespace std;
void rd(int &v) {
	char ch;
	for(ch='*'; ch<'0'||ch>'9'; ch=getchar());
	for(v=0; ch>='0'&&ch<='9'; ch=getchar()) v=v*10+ch-'0';
}
int n,FU[100005],len,a[100005];
int main() {
	cin>>n;
	ff(i,1,n) rd(a[i]);
	len=1;
	FU[1]=a[n];
	fr(i,n-1,1) {
		int k=upper_bound(FU+1,FU+1+len,a[i])-FU;
		if(k>len) FU[++len]=a[i];
		if(FU[k]>a[i]) FU[k]=a[i];
	}
	cout<<len;
}