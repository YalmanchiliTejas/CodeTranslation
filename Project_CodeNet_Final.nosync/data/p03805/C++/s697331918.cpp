#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cmath>
 
using namespace std;

int matrix[8][8];

int factorial(int n){
	if(n == 0) return 1;
	return n*(factorial(n-1));
}

void init(){
	for(int i = 0 ; i < 8; i++){
		for(int j = 0 ; j < 8; j ++){
			matrix[i][j] = 0;
		}
	}
}

int main()
{
	init();
	int N,M;
	cin>>N>>M;
	vector<int> intVec;
	for(int i = 0; i < M; i++){
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		matrix[a][b] = 1;
		matrix[b][a] = 1;
	}

	int count = 0;
	for(int i = 0; i < N; i++){
		intVec.push_back(i);
	}
	int index = 0;
	do{
		for(int i = 0;i < N-1; i++){
			if( matrix[intVec[i]][intVec[i+1]] != 1){
				break;
			}else if(i == N-2){
				count++;
			}
		}
		index++;
		next_permutation(intVec.begin(),intVec.end());
	}while(index < factorial(N-1));
	cout<<count<<endl;
	return 0;
}