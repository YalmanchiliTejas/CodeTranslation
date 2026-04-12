/*
	Copyright: razouq (c)
	Author: Anass BENDARSI
	Date: 08/07/2017 01:47:53
	flamers will **** you
*/
#include<bits/stdc++.h>
//#include<flamers.h>
#define ull unsigned long long
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> vect1, vect2;
	int x;
	for(int i = 0; i < n; i++){
		cin>>x;
		if(i % 2 == 0) vect1.push_back(x);
		else vect2.push_back(x);
	}
	
	if(n % 2 == 1) {
		for(int i = vect1.size()-1; i >= 0; i--){
			cout<<vect1[i]<<" ";
		}
		for(int i = 0; i < vect2.size(); i++){
			cout<<vect2[i]<<" ";
		}
	}
	else{
		for(int i = vect2.size()-1; i >= 0; i--){
			cout<<vect2[i]<<" ";
		}
		for(int i = 0; i < vect1.size(); i++){
			cout<<vect1[i]<<" ";
		}
	}
	return 0;
}
