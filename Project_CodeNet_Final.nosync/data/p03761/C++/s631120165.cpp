#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define SORT(c) sort((c).begin(),(c).end())
#define INF 1000000000
#define mod 1000000007

int main(){
cin.tie(0);
ios::sync_with_stdio(false);
	int N;
	cin>>N;
	int a[50][26]={0};
	REP(i,N){
		string s;
		cin>>s;
		REP(j,s.size()){
			a[i][s[j]-'a']++;
		}
	}
	int ans[26];
	REP(i,26)ans[i]=INF;
	REP(j,26){
		REP(i,N){
			ans[j]=min(ans[j],a[i][j]);
		}
	}
	bool f=true;
	REP(i,26){
		if(ans[i]>=INF)ans[i]=0;
		else f=false;
	}
	if(f){
		cout<<" "<<endl;
		return 0;
	}
	REP(i,26){
		REP(j,ans[i]){
			char c=i+'a';
			cout<<c;
		}
	}
	cout<<endl;
	return 0;
}
	