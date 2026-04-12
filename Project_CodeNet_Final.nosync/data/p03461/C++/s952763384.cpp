#include <bits/stdc++.h>

using namespace std;

int A,B,d[15][15],ans[105][105];
typedef pair<int, int> pi;

int main(){
//	freopen("graphxy.in","r", stdin);
//	freopen("graphxy.out","w", stdout);
	cin >> A >> B;
	for(int i = 1; i<=A; i++){ for(int j = 1; j<=B; j++) cin >> d[i][j]; }
	for(int a=0; a<=100; a++)
		for(int b=0; b<=100; b++)
			for(int x=1; x<=A; x++)
				for(int y=1; y<=B; y++)
					ans[a][b] = max(ans[a][b], d[x][y]-a*x-b*y);
	for(int i=1; i<=A; i++){
		for(int j = 1; j<=B; j++){
			int best = INT_MAX;
			for(int x=0; x<=100; x++){
				for(int y=0; y<=100; y++){
					best = min(best, ans[x][y]+i*x+j*y);
				}
			}
			if(best == d[i][j]){}
			else{
				cout << "Impossible";
				return 0;
			}
		}
	}
	cout << "Possible\n";
	cout << "200 10198\n";
	for(int i=0; i<100; i++){
		for(int j=0; j<100; j++) cout << i+1 << " " << 200-j << " " << ans[i][j] << "\n";
	}
	for(int i=1; i<100; i++) cout << i << " " << i+1 << " X\n";
	for(int i=101; i<200; i++) cout << i << " " << i+1 << " Y\n";
	cout << "1 200";
}
