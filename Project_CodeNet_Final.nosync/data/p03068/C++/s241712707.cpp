#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<stdio.h>
using namespace std;
typedef long long ll;

int main(){
	int N, K;
	string S;
	cin>>N>>S>>K;
	char k = S[K - 1];
	for(int i = 0; i < N; i++){
		if(S[i] != k)cout<<"*";
		else cout<<S[i];
	}
	cout<<endl;
}