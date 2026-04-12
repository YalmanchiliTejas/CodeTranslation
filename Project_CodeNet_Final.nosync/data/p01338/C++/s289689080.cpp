#include <iostream>
#include <cstring>
using namespace std;
#define rep(i,n) for(int i = 0 ; i < n ; i++)


int dp[1<<14][25];
int v[40];

int pt(int c){
	return c > 0 ? 50 + c * 10 : 0;
}
int toBit(int c[7],int add){
	int bit = 0;
	for(int i = 1 ; i < 7 ; i++){
		bit = (bit<<2) | c[i];
	}
	bit = (bit<<2) | (~v[add] ? v[add] : 0);
	return bit;
}

int f(int bit , int p){
	if(p == 25) return 0;
	if(~dp[bit][p]) return dp[bit][p];
	int c[7];
	rep(i,7) c[6-i] = bit >> (i*2) & 3;
	//if(p<=5){rep(i,7) cout << c[i];cout << "[" << bit << ":" << p << endl;}
	int ans = 0;
	if( p % 5 == 4 || p >= 20) return f(toBit(c,p+7),p+1)+pt(c[0]);

	rep(i,4){
		ans = max(ans,f(toBit(c,p+7),p+1)+pt(c[0]));
		if(~v[p]  )c[0] = (c[0]+1)%4;
		if(~v[p+1])c[1] = (c[1]+1)%4;
		if(~v[p+5])c[5] = (c[5]+1)%4;
		if(~v[p+6])c[6] = (c[6]+1)%4;
	}
	return dp[bit][p] = ans;
}
int main(){
	int T; cin >> T;
	while(T--){
		memset(v,-1,sizeof(v));
		rep(i,25) cin >> v[i] , v[i]--;
		memset(dp,-1,sizeof(dp));
		int bit = 0;
		rep(i,7) bit = (bit<<2) | (~v[i] ? v[i] : 0);
		//cout << ">"<< bit << endl;
		cout << f(bit,0) << endl;
	}
}