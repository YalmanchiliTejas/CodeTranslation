#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int r, c, countR[100], countC[100], temp;
char a[100][100];

int main(){
	cin >> r >> c;

	for(int row=0; row<r; row++){
		temp = 0;
		for(int col=0; col<c; col++){
			cin >> a[row][col];
			if(a[row][col] == '.'){
				countC[col]++;
				temp++;
			}
		}
		if(temp==c){
			countR[row]++;
		}
	}

	for(int row=0; row<r; row++){
		if(countR[row]){
			continue;
		}
		for(int col=0; col<c; col++){
			if(countC[col] == r){
				continue;
			}
			cout << a[row][col];
		}
		cout << endl;
	}
}