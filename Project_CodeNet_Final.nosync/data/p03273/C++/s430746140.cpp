#include <bits/stdc++.h>

#define mod 1000000007

using namespace std;
typedef long long ll; 
 
int main(void){
	
	int H, W;
	
	cin >> H >> W;
	
	vector<string> a(H);
	
	for(int i=0; i<H; i++)
		cin >> a[i];
	
	vector<bool> row(H, false);
	vector<bool> col(W, false);
	
	for(int i=0; i<H; i++){
		for(int j=0; j<W; j++){
			if(a[i][j] == '#'){
				row[i] = true;
				col[j] = true;
			}
		}
	}
	
	for(int i=0; i<H; i++){
		if(row[i]){
			for(int j=0; j<W; j++){
				if(col[j]){
					cout << a[i][j];
				}
			}
			cout << endl;
		}
	}	
	
	return 0;
}