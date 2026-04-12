// B - Great Ocean View
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin>>n;
	int ans = 0;
	int maxi = 1;
	for(int i=0; i<n; ++i){
		int h; cin>>h;
		if(maxi<=h){
			maxi = h;
			++ans;
		}
	}
	cout<< ans <<endl;
}