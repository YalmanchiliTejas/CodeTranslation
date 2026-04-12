#include <bits/stdc++.h>
#define fore(x,a,b) for(int x=a, qwerty=b; x<qwerty; x++)
#define ALL(a) (a).begin(),(a).end()
#define SZ(a) ((int)(a).size())
#define pb push_back
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
using namespace std;
typedef long long ll;
const int N=100500;
string s;
int d;
const int mod=1e9+7;
int dp[N][100][2];
int add(int a, int b){
	a+=b;
	if(a>=mod)a-=mod;
	return a;
}
int f(int i, int r, bool b){
	if(i==SZ(s))return !r;
	int &q=dp[i][r][b];
	if(q!=-1)return q;
	q=0;
	for(int j=(i==0);j<=9;j++){
		if(!b&&j>s[i]-'0')continue;
		q=add(q,f(i+1,(r+j)%d,b|(j<s[i]-'0')));
	}
	return q;
}
int f2(int i, int r, bool b){
	if(i==SZ(s)-1)return !r;
	int &q=dp[i][r][b];
	if(q!=-1)return q;
	q=r==0;
	for(int j=(i==0);j<=9;j++)q=add(q,f2(i+1,(r+j)%d,b));
	return q;
}
int main(){FIN;
	cin>>s>>d;
	memset(dp,-1,sizeof dp);
	int r=f2(0,0,0)-1+mod;r%=mod;
	memset(dp,-1,sizeof dp);
	r=add(r,f(0,0,0));
	cout<<r<<"\n";
}