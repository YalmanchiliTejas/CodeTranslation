#include<bits/stdc++.h>
#define rgi register int
#define ll long long
class fastin{
	private: int _ch,_f;
	public: template<typename _Tp> inline fastin& operator>>(_Tp&_x){
		_x=0; while(!isdigit(_ch)) _f|=(_ch==45),_ch=getchar();
		while(isdigit(_ch)) _x=(_x<<1)+(_x<<3)+(_ch^48),_ch=getchar();
		_f&&(_x=-_x,_f=0); return *this;}
	fastin() {_ch=_f=0;}
}fin;
class fastout{
	private: int _num[32],_head;
	public: int SUF; template<typename _Tp> inline fastout& operator<<(_Tp _x){
		_Tp _k; if(_x==0) {putchar('0'),putchar(SUF);return *this;} if(_x<0) putchar('-'),_x=-_x;
		while(_x>0) _k=_x/10,++_head,_num[_head]=(_x-(_k<<1)-(_k<<3))^48,_x=_k;
		while(_head>0) putchar(_num[_head]),--_head; putchar(SUF); return *this;}
	fastout() {_head=0,SUF=' ';}
}fout;
// ----------------------------
#define int ll
// using namespace std;
const int maxn=3004;
const int mod=998244353,inf=1000000007;

int n,s;
int a[maxn];
ll f1[maxn][maxn],f2[maxn][maxn],ans;

signed main()
{
	fin>>n>>s;
	for(rgi i=1;i<=n;++i) fin>>a[i];
	for(rgi i=1;i<=n;++i)
	{
		for(rgi j=0;j<=s;++j)
		{
			f2[i][j]=f2[i-1][j];
			if(j>=a[i])
			{
				int t=j-a[i];
				f1[i][j]=f2[i-1][t];
				if(!t) (f1[i][j]+=i)%=mod;
			}
			(f2[i][j]+=f1[i][j])%=mod;
		}
		(ans+=f1[i][s]*(n-i+1))%=mod;
	}
	fout.SUF='\n',fout<<ans;
	return 0;
}
// ----------------------------
// by imzzy
