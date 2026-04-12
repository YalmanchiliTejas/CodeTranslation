#include "bits/stdc++.h"
using namespace std;
const int N = 55;
int n;
long long arr[N];
long long sum;
long long k;
void big(){
	long long mx = -1;
	int idx = -1;
	for(int i = 1 ; i <= n ; ++i){
		if(arr[i] > mx){
			mx = arr[i];
			idx = i;
		}
	}
	long long val = mx / n;
	sum = 0;
	for(int i = 1 ; i <= n ; ++i){
		arr[i] += (i == idx) ? -n * val : val;
		sum += arr[i];
	}
	k += val;
}
void small(){
	while(1){
		int mx = -1;
		int idx = -1;
		for(int i = 1 ; i <= n ; ++i){
			if(arr[i] > mx){
				mx = arr[i];
				idx = i;
			}
		}
		if(mx < n){
			break;
		}
		for(int i = 1 ; i <= n ; ++i){
			arr[i] += (i == idx) ? -n : 1;
		}
		++k;
	}
}
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%lld" , arr + i);
		sum += arr[i];
	}
	while(sum > 1e5){
		big();
	}
	small();
	printf("%lld\n" , k);
}