#include<bits/stdc++.h>
using namespace std;

int main(){
	int a, max, all;
	cin >> a;
	int arr[a];
	for(int i=0; i<a; i++){
		cin >> arr[i];
	}
	max=arr[0]; all=1;
	for(int i=1; i<a; i++){
		if(arr[i]>=max){
			max=arr[i];
			all++;
		}
	}
	cout << all << endl;
}
