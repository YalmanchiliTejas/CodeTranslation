#include <bits/stdc++.h>
 using namespace std;
 #define rep(i,N) for(int i=0;i<int(N);++i)
 using ll = long long;
 const int INF = 2147483647;

int main() {
	int h,w;
	cin >> h >> w;
	char a[h][w];
	bool bw[w];
	bool bh[h];
	rep(i,w) bw[i]=0;
	rep(i,h) bh[i]=0;
	rep(i,h){
		rep(j,w){
			char c;
			cin >> c;
			a[i][j]=c;
		}
	}
	//行を見る
	rep(i,h){
		int cnt=0;
		rep(j,w){
			if(a[i][j]=='.')
				cnt++;
		}
		if(cnt==w) bh[i]=true;
	}
	//列を見る
	rep(i,w){
		int cnt=0;
		rep(j,h){
			if(a[j][i]=='.')
				cnt++;
		}
		if(cnt==h) bw[i]=true;
	}
	rep(i,h){
		rep(j,w){
			if(bh[i]==0&&bw[j]==0)
				cout << a[i][j];
		}
		if(bh[i]==0)
			cout << endl;
	}
}
