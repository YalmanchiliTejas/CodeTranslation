#include<bits/stdc++.h>
#define STDIO
#define MOD 1000000007
#define testbit(mask,i) (((mask)>>(i))&1)
#define setbit(mask,i) ((mask)|(1<<i))
#define delbit(mask,i) ((mask)^(1<<i))
#define lowbit(x) ((x)&(-x))
#define INF MOD
using namespace std;
string s;
int main(){
	#ifndef STDIO
		freopen("input.in","r",stdin);
		freopen("output.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>s;
	int acnt=0,bcnt=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='A')
			acnt++;
		else
			bcnt++;
	}
	if(acnt==0||bcnt==0)
		cout<<"No"<<endl;
	else
		cout<<"Yes"<<endl;
	return 0;
}
