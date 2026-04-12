#include <bits/stdc++.h>
#define inf 1000000007
#define mod 1000000007
//#pragma GCC optimize(2)
//#define int long long
using namespace std;
template <typename T> void read(T &x){
	x=0;char ch=getchar();int fh=1;
	while (ch<'0'||ch>'9'){if (ch=='-')fh=-1;ch=getchar();}
	while (ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	x*=fh;
}
template <typename T> void write(T x) {
	if (x<0) x=-x,putchar('-');
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
template <typename T> void writeln(T x) {
	write(x);
	puts("");
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	int a=0,b=0;
	for(int i=0;i<3;i++)
		if(s[i]=='A')
			a++;
		else
			b++;
	if(a&&b) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}
