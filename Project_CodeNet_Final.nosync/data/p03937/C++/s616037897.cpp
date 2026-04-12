#include <bits/stdc++.h>
using namespace std;

int main(){
	int H,W;
	cin >> H >> W;
	vector<string> A(H);
	for(int i=0;i<H;i++)cin >> A[i];
	int h=0,w=0;
	A[0][0]='.';
	for(;;){
		if(h==H-1 && w==W-1)break;
		if(w<W-1 && A[h][w+1]=='#'){
			w++;
			A[h][w]='.';
			continue;
		}
		if(h<H-1 && A[h+1][w]=='#'){
			h++;
			A[h][w]='.';
			continue;
		}
		cout << "Impossible" << endl;
		return 0;
	}
	for(int i=0;i<H;i++)
		for(int j=0;j<W;j++){
			if(A[i][j]=='#'){
				cout << "Impossible" << endl;
				return 0;
			}
		}
		
	cout << "Possible" << endl;
	return 0;
}