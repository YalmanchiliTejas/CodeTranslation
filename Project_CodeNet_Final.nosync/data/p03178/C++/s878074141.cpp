#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define ll long long
#define pq priority_queue
#define mp make_pair
#define pii pair<int,int>

const int mod=1e9+7;
int lowbit(int x) {return x&(-x);}

string s;
int d;
int f[10010][110];

int getf1(int l,int x) {
	if (f[l][x]!=-1) return f[l][x];
	if (l>=s.size()) {
		if (x==0) return 1;
		else return 0;
	}
	int res=0;
	for (int i=0;i<10;i++) {
		res+=getf1(l+1,(x+d-i%d)%d);
		res%=mod;
	}
	return f[l][x]=res;
}

int getf2(int l,int x) {
	if (l>=(int)s.size()) {
		if (x==0)return 1;
		else return 0;
	}
	int res=0;
	for (int i=0;i<(int)(s[l]-'0');i++) {
//		cout<<l<<" "<<i<<" "<<(x+d-i%d)%d<<" "<<res<<endl;
		res+=getf1(l+1,(x+d-i%d)%d);
		res%=mod;
	}
	int i=(int)(s[l]-'0');
	res+=getf2(l+1,(x+d-i%d)%d);
	res%=mod; 
	return res;
}

int main(){
	memset(f,-1,sizeof(f));
	cin>>s>>d;
	cout<<(getf2(0,d)+mod-1)%mod;
	return 0;
}
