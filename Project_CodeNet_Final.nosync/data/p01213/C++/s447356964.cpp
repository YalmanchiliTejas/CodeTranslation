#include<string>
#include<iostream>

#define	rep(i,n)	for(int i=0;i<(n);i++)

using namespace std;

string LCS(const string &s,const string &t){
	const int LMAX=300;
	static int dp[LMAX+1][LMAX+1],from[LMAX+1][LMAX+1];
	int slen=s.length(),tlen=t.length();

	rep(i,slen+1)	dp[i][0]=0,from[i][0]=-1;
	rep(j,tlen+1)	dp[0][j]=0,from[0][j]=-1;

	for(int i=1;i<=slen;i++)for(int j=1;j<=tlen;j++){
		dp[i][j]=0;
		int a[]={dp[i][j-1],dp[i-1][j],dp[i-1][j-1]+(s[i-1]==t[j-1])};
		rep(k,3)if(dp[i][j]<a[k]){ dp[i][j]=a[k]; from[i][j]=k; }
	}

	int l=dp[slen][tlen];
	string ans(l,'@');
	for(int x=tlen,y=slen;~from[y][x];){
		switch(from[y][x]){
			case 0: x--; break;
			case 1: y--; break;
			case 2: x--; y--; ans[--l]=s[y]; break;
		}
	}

	return ans;
}

int main(){
	for(string s;cin>>s,s!="#END";){
		int len=s.length();
		string ans;
		for(int i=1;i<len;i++){
			string tmp=LCS(s.substr(0,i),s.substr(i));
			if(ans.length()<tmp.length())	ans=tmp;
		}
		cout<<ans<<endl;
	}

	return 0;
}