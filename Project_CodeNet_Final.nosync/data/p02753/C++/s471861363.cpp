#pragma GCC optimize("-Ofast","-funroll-all-loops")
#include<bits/stdc++.h>
#define int long long
#define lowbit(x) (x &(-x))
#define endl '\n'
using namespace std;
const int INF=0x3f3f3f3f;
const int dir[4][2]={-1,0,1,0,0,-1,0,1};
const double PI=acos(-1.0);
const double e=exp(1.0);
const double eps=1e-10;
const int M=1e9+7;
const int N=2e5+10;
typedef long long ll;
typedef pair<int,int> PII;
typedef unsigned long long ull;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	string s;
	cin>>s;
	if(s[0]==s[1]&&s[1]==s[2])
		cout<<"No"<<endl;
	else
		cout<<"Yes"<<endl;
	return 0;
}
