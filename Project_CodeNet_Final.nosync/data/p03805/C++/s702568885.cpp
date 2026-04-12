#include<iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int Max = 1000000;
int main(){
  	int N, M;
  	cin >> N >> M;
  	bool e[N][N];

  	for(int i=0;i<N;i++){
  		for(int j=0;j<N;j++) e[i][j] = false;
  	}

  	int check[N];
  	int a, b;

  	for(int i=0;i<N;i++) check[i] = i;

  	for(int i=0;i<M;i++){
  		cin >> a >> b;
  		e[a-1][b-1] = true;
  		e[b-1][a-1] = true;
  	}

  	int ans = 0;
  	do{
  		bool flag = true;
  		for(int i=0;i<N-1;i++){
  			if(!e[check[i]][check[i+1]]){
  				flag = false;
  				break;
  			}
  		}
  		if(flag) ans++;
  	}while(next_permutation(check+1, check+N));

  	cout << ans <<endl;


    
  	return 0;
}
