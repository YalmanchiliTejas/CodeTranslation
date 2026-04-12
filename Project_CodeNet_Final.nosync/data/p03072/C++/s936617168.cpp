#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int h[50];
	int cnt=0;
	for(int i=0;i<n;i++){
		bool yn=1;
		cin>>h[i];
		for(int j=0;j<i;j++){
			if(h[i]<h[j]){
				yn=0;
				break;
			}
		}
		if(yn==1){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
} 