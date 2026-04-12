#include <bits/stdc++.h>
using namespace std;

int h,w;
char a[15][15];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> h >> w;
	for (int i=1;i<=h;i++){
		for (int j=1;j<=w;j++){
			cin >> a[i][j];
		}
	}
	int ph=1,pw=1,ok=a[1][1]=='#';
	a[ph][pw]='.';
	while (ph<h||pw<w){
		int right=pw<w&&a[ph][pw+1]=='#';
		int down=ph<h&&a[ph+1][pw]=='#';
		if (right^down){
			ph+=down;
			pw+=right;
			a[ph][pw]='.';
		}else{
			ok=0;
			break;
		}
	}
	for (int i=1;i<=h;i++){
		for (int j=1;j<=w;j++){
			ok&=a[i][j]=='.';
		}
	}
	cout << (ok?"P":"Imp") << "ossible\n";
}