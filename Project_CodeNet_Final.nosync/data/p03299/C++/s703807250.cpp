#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=105,p=1000000007;
int read(){
	int f=1,g=0;
	char ch=getchar();
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') f=-1;
	for (;isdigit(ch);ch=getchar()) g=g*10+ch-'0';
	return f*g;
}
int qpow(int x,int k){
	int t=1;
	for (;k;k>>=1){
		if (k&1) t=(ll)t*x%p;
		x=(ll)x*x%p;
	}
	return t;
}
int n,m,K,a[N];
void check(int &x,int y){if ((x+=y)>=p) x-=p;}
typedef pair<int,int> pr;
pr work(int dep,int l,int r){
	int d=0x3f3f3f3f,las=l;
	pr ans=make_pair(2,1);
	for (int i=l;i<=r;i++) d=min(d,a[i]);
	for (int i=l;i<=r;i++)
	if (a[i]==d) {
		check(ans.second,ans.second);
		if (las<i){
			pr t=work(d+1,las,i-1);
			ans.first=(ll)ans.first*t.first%p;
			ans.second=(ll)ans.second*(t.second+t.first)%p;
		}
		las=i+1;
	}
	if (las<=r){
		pr t=work(d+1,las,r);
		ans.first=(ll)ans.first*t.first%p;
		ans.second=(ll)ans.second*(t.second+t.first)%p;
	}
	check(ans.second,p-ans.first);
	ans.first=(ll)ans.first*qpow(2,d-dep)%p;
	check(ans.second,ans.first);
	return ans;
}
int main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	printf("%d\n",work(1,1,n).second);
	return 0;
}