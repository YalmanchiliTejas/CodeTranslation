#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 1e5+2;
int N;
string s;
int ans[MAX_N];

bool go(int a1, int a2)
{
	ans[0]=a1;ans[1]=a2;
	if(!a1){ // truth
		if(s[0]=='o') ans[N-1]=a2;
		else ans[N-1]=a2^1;
	}else{  // lie
		if(s[0]=='o') ans[N-1]=a2^1;
		else ans[N-1]=a2;
	}
	for(int i=1;i<N-2;++i){
		// determine i+1
		int cur = ans[i];
		int prv = ans[i-1];
		if(!cur){ //truth
			if(s[i]=='o') ans[i+1]=prv;
			else ans[i+1]=prv^1;
		}else{ //lie
			if(s[i]=='o') ans[i+1]=prv^1;
			else ans[i+1]=prv;
		}
	}
	for(int i=0;i<N;++i)if(ans[i]<0)return false;
	for(int i=0;i<N;++i){
		int cur=ans[i];
		int prv = (i-1+N)%N;
		int nxt = (i+1)%N;
		if(!cur&&((s[i]=='o') != (ans[prv]==ans[nxt]))) return false;
		if(cur&&((s[i]=='x')!=(ans[prv]==ans[nxt]))) return false;
	}
	return true;
}

void solve()
{
	for(int f=0;f<2;++f)for(int s=0;s<2;++s){
		memset(ans,-1,sizeof(ans));
		if(go(f,s)){
			string t;
			for(int i=0;i<N;++i){
				if(ans[i]) t+='W';
				else t+='S';
			}
			cout << t << '\n';
			return;
		}
	}
	cout << -1 << '\n';
}

int main()
{
	cin >> N >> s;
	solve();
	return 0;
}