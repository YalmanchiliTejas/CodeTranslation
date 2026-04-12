#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
typedef long long ll;

int main(){
	int N;
	cin>>N;
	vector<int> mt(N);
	for(int i = 0; i < N; i++){
		cin>>mt[i];
	}
	int h = mt[0];
	int ct = 1;
	for(int i = 1; i < N; i++){
		if(h <= mt[i])ct++;
		h = max(h, mt[i]);
	}
	cout<<ct<<endl;
	return 0;

}