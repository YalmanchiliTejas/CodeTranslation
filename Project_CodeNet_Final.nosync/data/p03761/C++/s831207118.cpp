#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<int,int> p;
const int inf=(1<<30);
#define rep(i,a,n)	for(int i=a;i<n;i++)
#define rrep(i,a,n) for(int i=(a-1);i>=n;i--)

	int cnt[26];
	int current[26];
int main(){
	ll n;
	cin>>n;
	string s[55];
	rep(i,0,n)cin>>s[i];
	rep(i,0,s[0].size()){
		int x=s[0][i]-'a';
		cnt[x]++;
	}
	rep(i,1,n){
		rep(j,0,s[i].size()){
			int x=s[i][j]-'a';
			current[x]++;
		}
		rep(i,0,26)cnt[i]=min(cnt[i],current[i]);
		memset(current,0,sizeof(current));
	}
	rep(i,0,26){
		while(cnt[i]>0){
			char x=i+'a';
			cout<<x;
			cnt[i]--;
		}
	}
}