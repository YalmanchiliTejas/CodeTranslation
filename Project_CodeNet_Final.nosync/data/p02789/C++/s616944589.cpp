#include<iostream>
#include<string>
#include<stdio.h>
#include<cctype>
#include<algorithm>
#include<climits>
#include<cmath>
#include<map>
#include<vector>
#define INF INT_MAX
using namespace std;

int N;
int M;

int main(){
	cin >> N >> M;
	if (N == M){
		cout << "Yes" << endl;
	}
	else{
		cout << "No" << endl;
	}
	return 0;
}