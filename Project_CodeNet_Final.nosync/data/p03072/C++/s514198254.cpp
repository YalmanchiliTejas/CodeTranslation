#include <vector> // vectorを使うためにインクルードする
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
	vector<int> mountain; // <T>でT型のvector
	int n;
	cin >> n;
	while(n--) {
		int x;
		cin >> x;
		mountain.push_back(x);
	}
	int ans = 1;
	for(int i=0; i < mountain.size()-1; i++){
		if(mountain[i+1]-mountain[i]>=0){
			bool b = true;
			for(int j=0; j < i+1; j++){
				if(mountain[i+1]-mountain[j]<0){
					b=false;
					break;
				}
			}
			if(b==true) ans+=1;
		}
	}
	cout << ans << endl;
}
