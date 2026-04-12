//第8回シンデレラガール総選挙は是非本田未央ちゃんに投票をお願いします！
//ファンのことも他のアイドルの子たちのことも本当に大事にしてて、今まで周りに色んなものを与えてくれました。
//今度は私たちが未央ちゃんにお返しをする番です。みんなでガラスの靴を履かせてあげましょう！
// #本田未央を一番星に #本田未央を令和のシンデレラガールに #第8回シンデレラガール総選挙
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
lint mo=1000000007;
template <class typ> struct BIT{
	vector<typ> x;
	BIT(int n):x(n,0){}
	typ sum(int a,int b){
		if(a>b) return 0;
		if(a==0){
			typ s=0;
			for(int i=b;i>=0;i=(i&(i+1))-1){
				s+=x[i];s%=mo;
			}
			return s;
		}
		else return (sum(0,b)-sum(0,a-1)+mo)%mo;
	}
	void add(int ind,typ f){
		for(int i=ind;i<x.size();i|=i+1){
			x[i]+=f;x[i]%=mo;
		}
	}
};
vector<int> le;
lint dp[200100][2][2];
int main()
{
	int n,m,now=0;string s;
	cin>>n>>m;
	cin>>s;s+='X';
	rep(i,m){
		now++;
		if(s[i]!=s[i+1]){
			le.pb(now);now=0;
		}
	}
	if(le.size()==1){
		memset(dp,0,sizeof(dp));
		dp[1][0][0]=dp[1][1][1]=1;
		REP(i,1,n) rep(j,2){
			dp[i+1][0][j]+=dp[i][0][j]+dp[i][1][j];
			dp[i+1][1][j]+=dp[i][0][j];
			dp[i+1][0][j]%=mo;
			dp[i+1][1][j]%=mo;
		}
		cout<<(dp[n][0][0]+dp[n][0][1]+dp[n][1][0])%mo<<endl;
		return 0;
	}
	if(n%2>0){
		cout<<0<<endl;return 0;
	}
	int ma=le[0]/2+1;
	for(int i=0;i<(int)le.size()-1;i+=2){
		if(le[i]%2>0) ma=min(ma,le[i]/2+1);
	}
	//cout<<ma<<endl;
	BIT<lint> bit(n/2+10);
	bit.add(0,1);
	REP(i,1,n/2){
		//cout<<i<<' '<<bit.sum(max(0,i-ma),i-1)<<endl;
		bit.add(i,bit.sum(max(0,i-ma),i-1));
	}
	lint out=0;
	REP(i,1,min(n/2,ma)+1){
		//cout<<i<<endl;
		out+=bit.sum(n/2-i,n/2-i)*i*2;out%=mo;
	}
	cout<<out<<endl;
}
