#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int comp(const void* a, const void* b){
	return *(int*)a - *(int*)b;
}

int main(){
	int n, h[25], cnt = 0, ans = 0;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> h[i];
		for(int j = 0; j < i; j++){
			if(h[j] <= h[i]){
				cnt++;
			}
		}
		if(cnt == i){
			ans++;
		}
		cnt = 0;
	}
	cout << ans << endl;
}