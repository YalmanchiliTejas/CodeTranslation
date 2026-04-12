#include <bits/stdc++.h>
#define int long long
#define INF 1000000007
#define SMO -1000000007
#define P pair<int,int>
#define fi first
#define se second
using namespace std;
bool prime(int n){
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0)return false;
	}
	return n!=1;
}
int kaicnt;
int kai(int n,int x){
	kaicnt++;
	if(kaicnt==x){
		kaicnt=0;
		return n%INF;
	}
	return (kai(n-1,x)%INF*n)%INF;
}
int conbi(int n,int x){
	x=min(x,n-x+1);
	return kai(n,x)/kai(x,x);
}
int pow_mod(int n,int k,int m){
	if(k==0)return 1;
	else if(k%2==1)return pow_mod(n,k-1,m)*n%m;
	else {
		int t=pow_mod(n,k/2,m);
		return t*t%m;
	}
}
int n;
map<char,int>mp;
string s;
signed main(){
	cin>>n;
	for(int i=0;i<26;i++){
		mp[(char)('a'+i)]=INF;
	}
	for(int i=0;i<n;i++){
		cin>>s;
		map<char,int>memo;
		for(int j=0;j<26;j++){
			memo[(char)('a'+i)]=0;
		}
		for(int j=0;j<s.size();j++){
			memo[s[j]]++;
		}
		for(int j=0;j<26;j++){
			mp[(char)('a'+j)]=min(mp[(char)('a'+j)],memo[(char)('a'+j)]);
		}
	}
	for(int i=0;i<26;i++){
		if(mp[(char)('a'+i)]==INF)continue;
		for(int j=0;j<mp[(char)('a'+i)];j++)cout<<(char)('a'+i);
	}
	cout<<endl;
}