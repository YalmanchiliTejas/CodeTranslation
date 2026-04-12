#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#define rep(i,n) for(int i = 0; i < n;++i)
using namespace std;

int main(){
	vector<string> v(50);
	int alpha[50][26];
	int alpha1[26];
	int n;
	cin >> n;
	rep(j,50){
		rep(i,26){
			alpha[j][i] = 0;
			alpha1[i] =0;
		}
	}

	rep(i,n){
		cin >> v[i];
		rep(j,v[i].length())
			alpha[i][v[i][j] - 97]++;
	}


	rep(i,26){
		alpha1[i] = 114514810;
	}
	rep(i,n){
		rep(j,26){
			if(alpha1[j] > alpha[i][j])
				alpha1[j] = alpha[i][j];
		}
	}


	rep(i,26)
		rep(j,alpha1[i])
			printf("%c",i+97);

	cout << endl;


	return 0;


}