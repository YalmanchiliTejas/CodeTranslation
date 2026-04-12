#include <iostream>
#include <map>
#include <algorithm>    
#include <vector>       
#include <set>
#include <utility>  
#include <cstring>
#include <stdio.h>
#include <limits.h>
#include <queue>
#include <algorithm> 
#define MAX_DOUBLE  40000000000.0 
#include <math.h> 
#include <unistd.h>

using namespace std;

long long res[3000][3000];


long long min(long long a, long long b){
	if(a > b) return b;
	return a;
}

long long max(long long a, long long b){
	if(a < b) return b;
	return a;
}

int main(){
	vector<long long> vec;
	int n;
	cin>>n;
	for(int i =0; i<n; i++){
		int a;
		cin>>a;
		vec.push_back(a);
	}
	
	
	for(int i = n-1; i>=0; i--){
		for(int j = i; j<n; j++){
			if(i == j){
				res[i][j] = vec[i];
			}else{
				long long win = max(vec[j] - res[i][j-1], vec[i] - res[i+1][j]);
				res[i][j] = win;
			}
		}
	}
	
	cout<<res[0][n-1];
	
}
