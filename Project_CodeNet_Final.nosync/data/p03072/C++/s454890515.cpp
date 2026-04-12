//Author: Fuadul Hasan(fuadul202@gmail.com)
#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N   = 2e5 + 5;

int main(){
	
	int n;
	cin>>n;

	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}	
	int cnt = 0;
	for(int i=0;i<n;i++){
		bool f = true;
		for(int j=0;j<i;j++){
			if(a[j]>a[i]){
				f = false;
			}
		}
		if(f){
			cnt++;
		}
	}


	cout<<cnt<<endl;	

	return 0;
}