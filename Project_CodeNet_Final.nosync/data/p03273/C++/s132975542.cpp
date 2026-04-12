#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
typedef long long LL;
typedef pair<int,int> P;

int main(){
	int H, W;
	cin >> H >> W;
	vector<string> a(H);
	rep(i,H) cin >> a[i];
	vector<bool> ver(W), hor(H);
	rep(j,W){
		int num=0;
		rep(i,H) if(a[i][j]=='.') num++;
		if(num==H) ver[j]=true;
	}
	rep(i,H){
		int num=0;
		rep(j,W) if(a[i][j]=='.') num++;
		if(num==W) hor[i]=true;
	}
	vector<string> ans(H);
	rep(i,H){
		if(hor[i]) continue;
		rep(j,W){
			if(ver[j]) continue;
			ans[i].push_back(a[i][j]);
		}
	}
	rep(i,H){
		if(ans[i].size()==0) continue;
		cout << ans[i] << endl;
	}

	return 0;
}