#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
#include<cassert>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
//問題文および制約はちゃんと確認しよう！
//サイズは10^5じゃなくて2×10^5とかかもしれないし、重要な制約・条件を見落としているかも
//とりあえずサンプルを読んでから解法を考えよう？
lint s[100100];
vector<lint> sum[100100],rsum[100100];
int n;
/*lint cal(int A,int x){
	if(A==x) return 0;
	if(A%x==0){
		if(A*2<=n-1) return 0;
	}
	return sum[x][(n-1-A)/x]+rsum[x][(n-1-A)/x];
}*/
int main()
{
	lint out=0;
	cin>>n;
	rep(i,n) cin>>s[i];
	REP(i,1,100050){
		lint su=0,r=n-1,l=0;
		while(1){
			r-=i;
			if(r<=0 || r==l) break;
			su+=s[r];
			l+=i;
			if(l>=n-1 || r==l) break;
			su+=s[l];
			if(r>i) out=max(out,su);
		}
	}
	/*REP(A,2,n-1){
		for(int i=1;i*i<=(n-1-A);i++){
			if((n-1-A)%i==0){
				out=max(out,cal(A,i));
				out=max(out,cal(A,(n-1-A)/i));
			}
		}
	}*/
	cout<<out<<endl;
}
