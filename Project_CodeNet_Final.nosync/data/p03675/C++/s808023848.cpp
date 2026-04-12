/*
 * 17-07-01_ARC077_C.cpp
 *
 *  Created on: 2017/07/01
 *      Author: ryoma
 */

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
int a[2*100000+10];
vector<int> b;
int main(){
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	int i;
	for(i=n-1;i>=0;i-=2){
		b.push_back(a[i]);
	}
	i+=2;
	i=!i;
	for(;i<n;i+=2){
		b.push_back(a[i]);
	}
	for(int i=0;i<n;i++){
		cout << b[i];
		if(i+1<n){
			cout << " ";
		}
	}
	cout << endl;
	return 0;
}



