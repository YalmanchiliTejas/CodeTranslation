#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+5,M=2e4+5,inf=0x3f3f3f3f,mod=1e9+7;
#define mst(a,b) memset(a,b,sizeof a)
#define lx x<<1
#define rx x<<1|1
#define reg register
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define il inline
int b[26];
int main(){
	int n;cin>>n;
	mst(b,0x3f);
	string a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++){
		int tmp[26]={};
		for(int j=0;j<a[i].size();j++){
			tmp[a[i][j]-'a']++;
		}
		for(int j=0;j<26;j++)
			if(b[j]>tmp[j]) b[j]=tmp[j];
	}
	string ans;
	for(int i=0;i<26;i++)
	{
		for(int j=0;j<b[i];j++) ans.push_back(i+'a');
	}
	sort(ans.begin(),ans.end());cout<<ans<<endl;
	return 0;
}