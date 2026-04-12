#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
int main(void){
	int H,W,cnt=0;
	char c;
	cin>>H>>W;
	rep(y,H)rep(x,W)cin>>c, cnt+=c=='#';
	cout<<(cnt==H+W-1 ? "Possible" : "Impossible")<<endl;
	return 0;
}
