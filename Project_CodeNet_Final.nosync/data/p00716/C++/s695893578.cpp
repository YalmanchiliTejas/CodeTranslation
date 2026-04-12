#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

long long int calc(long long int type, double rate, long long int decr, long long int fund, long long int year){
	if(type == 0){
		
		int interest = 0;
		
		for(int i = 0; i < year; i++){
			interest += fund * rate;
			fund -= decr;
		}
		
		fund += interest;
		
	}else if(type == 1){
		for(int i = 0; i < year; i++){
			fund *= (1 + rate);
			fund -= decr;
		}
	}
	return fund;
}

int main(){
	
	int M;
	
	cin >> M;
	
	for(int loop = 0; loop < M; loop++){
		long long int fund, year, n, max;
		cin >> fund >> year >> n;
		max = 0;
		for(int i = 0; i < n; i++){
			long long int type, decr, result;
			double rate;
			cin >> type >> rate >> decr;
			result = calc(type, rate, decr, fund, year);
			if(max < result){
				max = result;
			}
		}
		printf("%lld\n", max);
	}
	
	return 0;
}