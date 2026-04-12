#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int main(){
	
	long long int N;
	
	cin >> N;
	
	long long int a[100];
	
	for(int i = 0; i < N; i++){
		cin >> a[i];
	}
	
	long long int ans = 0;
	
	while(true){
		long long int max = N - 1;
		long long int index = -1;
		for(int i = 0; i < N; i++){
			if(max < a[i]){
				max = a[i];
				index = i;
			}
		}
		if(index == -1){
			break;
		}
		long long int div = a[index] / N;
		ans += div;
		a[index] -= div * (N + 1);
		for(int i = 0; i < N; i++){
			a[i] += div;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}

