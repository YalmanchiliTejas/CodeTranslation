#include<iostream>
#include<vector>
#include<string>
#include<algorithm>	
#include<map>
#include<set>
#include<utility>
#include<cmath>
#include<cstring>
#include<queue>
#include<cstdio>
#include<sstream>
#include<iomanip>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define pb push_back
#define mp make_pair
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)
using namespace std;
//kaewasuretyuui
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef vector<vp> vvp;
typedef pair<int,pii> pip;
typedef vector<pip>vip;
const double PI=acos(-1);
const double EPS=1e-8;
const int inf=1e8;
string LCS(string &a,string &b){
	const int LMAX=300;
	int m=a.size(),n=b.size();
	int dp[LMAX+1][LMAX+1],from[LMAX+1][LMAX+1];
	rep(i,m+1)dp[i][0]=0,from[i][0]=-1;
	rep(i,n+1)dp[0][i]=0,from[0][i]=-1;
	rep(i,m)rep(j,n){
		if(a[i]==b[j]){
			dp[i+1][j+1]=dp[i][j]+1;
			from[i+1][j+1]=2;
		}else{
			if(dp[i][j+1]<dp[i+1][j]){
				dp[i+1][j+1]=dp[i+1][j];
				from[i+1][j+1]=1;
			}else{
				dp[i+1][j+1]=dp[i][j+1];
				from[i+1][j+1]=0;
			}
		}
	}
	int idx=dp[m][n];
	string out(idx,'!');
	for(int i=m,j=n;~from[i][j];){
		switch(from[i][j]){
			case 0:i--;break;
			case 1:j--;break;
			case 2:i--;j--;idx--;out[idx]=a[i];break;
		}
	}
	return out;
}
int main(){
	string s;
	while(cin>>s,s!="#END"){
		int out=0;
		string ans="";
		rep(i,s.size()-1){
			string a=s.substr(0,i+1);
			string b=s.substr(i+1);
			string t=LCS(a,b);
			if(t.size()>out){
				out=t.size();
				ans=t;
			}
		}
		cout<<ans<<endl;
	}
}