#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

bool t[2000000];

int main(){
	
	int n, m, tmax, tset;
	
	while(true){
		for(int i = 0; i < 2000000; i++){
			t[i] = false;
		}
		cin >> n >> m;
		if(n == 0 && m == 0){
			break;
		}
		tmax = 0;
		for(int i = 0; i < n + m; i++){
			cin >> tset;
			t[tset] = true;
			if(tmax < tset){
				tmax = tset;
			}
		}
		int count, count_max;
		count = 0;
		count_max = 0;
		for(int i = 1; i <= tmax; i++){
			if(t[i]){
				if(count_max < count + 1){
					count_max = count + 1;
				}
				count = 0;
			}else{
				count++;
			}
		}
		printf("%d\n", count_max);
	}
	
	return 0;
}