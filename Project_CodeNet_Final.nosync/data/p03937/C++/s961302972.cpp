#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
#include<set>
#include<numeric>
#include<map>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i = 0;i<((int)(n));i++)
#define reg(i,a,b) for(int i = ((int)(a));i<=((int)(b));i++)
#define irep(i,n) for(int i = ((int)(n)-1);i>=0;i--)
#define ireg(i,a,b) for(int i = ((int)(b));i>=((int)(a));i--)
typedef long long ll;
typedef pair<ll, ll> mp;
ll MOD = 1e9+7;
//LLONG_MIN

//

int main(void){
	bool can=true;
	ll h,w,x=0,y=0;
	string s[10];
	cin>>h>>w;
	rep(i,h)cin>>s[i];
	while(x<w-1 || y<h-1){
		s[y][x]='*';//通った場所は別の文字にする
		if(s[y][x+1]=='#' && s[y+1][x]=='#'){
			can=false;
			break;
		}else if(s[y][x+1]=='#'){
			x++;
		}else if(s[y+1][x]=='#'){
			y++;
		}else{
			can=false;
			break;
		}
		s[y][x]='*';
		// printf("%lld,%lld\n",x,y);
	}
	rep(i,h)rep(j,w)if(s[i][j]=='#')can=false;
	cout<<(can?"Possible":"Impossible")<<endl;
	return 0;
}