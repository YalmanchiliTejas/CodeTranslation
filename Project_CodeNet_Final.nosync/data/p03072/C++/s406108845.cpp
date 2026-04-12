#include "bits/stdc++.h"
using namespace std;

int n,h,ret=0,mx=0;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	for(int i=0;i<n;i++){
		cin>>h;
		if(i==0){
			mx=h;
			ret++;
		}
		else if(h>=mx){
			mx=h;
			ret++;
		}
	}
	cout<<ret;
	return 0;
}