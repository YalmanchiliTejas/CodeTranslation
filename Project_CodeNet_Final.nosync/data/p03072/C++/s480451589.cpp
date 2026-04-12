#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<((int)(n));i++)
#define reg(i,a,b) for(int i = ((int)(a));i<=((int)(b));i++)
#define irep(i,n) for(int i = ((int)(n)-1);i>=0;i--)
#define ireg(i,a,b) for(int i = ((int)(b));i>=((int)(a));i--)
typedef long long ll;

/*
*/

ll n,h[100010],b=-1e18,ans=0;

void init(){
	cin>>n;
	rep(i,n)cin>>h[i];
	cerr<<"初期化終了"<<endl;
}

int main(void){
	init();
	rep(i,n){
		if(b<=h[i]){
			ans++;
			b=h[i];
		}
	}
	cout<<ans<<endl;
	return 0;
}