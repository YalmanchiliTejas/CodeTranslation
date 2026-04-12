#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i,n) for(int i=1;i<=(n);i++)
#define rep0(i,n) for(int i=0;i<(n);i++)

const ll INF=1e9+7;
int c['z'+1];
int f['z'+1];
int n;
int main()
{
	/*freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);*/
	cin>>n;
	for(int i='a';i<='z';i++){
		f[i]=INF;
	}
	rep(i,n){
		string s;
		cin>>s;
		memset(c,0,sizeof(c));
		rep0(i,s.size()){
			c[s[i]]++;
		}
		for(int j='a';j<='z';j++){
			f[j]=min(f[j],c[j]);
		}
	}
	for(int i='a';i<='z';i++){
		rep(j,f[i]){
			char t=i;
			cout<<t;
		}
	}
	return 0;
}