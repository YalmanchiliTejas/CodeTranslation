#include <bits/stdc++.h>
using namespace std;
int main(){
	int x, jumlah=0, maks=-9999999999	;
	cin >> x;
	int h[x+1];
	h[0]=0;
	for(int i=1;i<=x;i++){
		cin >> h[i];
		if(maks<=h[i]){
			maks=h[i];
		}
		if(maks<=h[i]){
			jumlah++;
		}
	}
	cout << jumlah << endl;
}