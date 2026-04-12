#include<iostream>
#include<string>
#include<algorithm>
#include<bits/stdc++.h>
#include<vector>
 
using namespace std;


int main(){
	int N,K; string S;
	cin >> N >> S >> K;
	for(int i=0; i<S.size(); i++){
		if(S[K-1]!=S[i])
		S[i]='*';
	}
	cout << S << endl;
		}