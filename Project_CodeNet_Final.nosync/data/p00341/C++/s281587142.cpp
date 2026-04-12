#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define rrep(i,n) for(int i=n-1;i>=0;--i)
#define yesno(flg) if(flg){cout<<"yes"<<endl;}else{cout<<"no"<<endl;}
#define vi vector<int>
#define MAX_N 200005
#define i197 1000000007

using namespace std;


typedef long long ll;
typedef pair<ll,ll> P1;
typedef pair<int,P1> P2;
const int inf=1000000000;
P1 xy[MAX_N]={};

int main() {
	int a[12];
	rep(i,12)cin>>a[i];
	sort(a,a+12);
	bool flg=true;
	rep(i,3){
		rep(k,3){
			if(a[i*4+k]!=a[i*4+k+1])flg=false;
		}
	}
	yesno(flg);
	return 0;
}

