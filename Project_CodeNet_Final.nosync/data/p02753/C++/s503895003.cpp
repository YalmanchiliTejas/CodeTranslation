#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define F first
#define S second
#define mkp make_pair
#define pii pair<int,int>
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e5+5;

int main(){
	char s[5];
	cin>>s;
	int flag1=0,flag2=0;
	for(int i=0;i<3;i++){
		if(s[i]=='A')flag1=1;
		if(s[i]=='B')flag2=1;
	}
	if(flag1&&flag2)cout<<"Yes";
	else cout<<"No";
	return 0;
}
