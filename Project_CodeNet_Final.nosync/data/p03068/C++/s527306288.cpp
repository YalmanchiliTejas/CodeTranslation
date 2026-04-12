#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
#define ALL(v) (v).begin(),(v).end()
#define INF 1e9
#define MOD 1e9+7
typedef long long llong;
using namespace std;

int main(){
	int n,k;
	string s;
	cin>>n>>s>>k;
	
	k--;
	
	REP(i,n){
		if(s[i]==s[k]) cout<<s[i];
		else cout<<'*';
	}
	cout<<endl;
}