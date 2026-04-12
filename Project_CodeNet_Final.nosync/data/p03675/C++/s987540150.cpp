#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	long long n;
	cin >> n;
	long long a[n];
	for(long long i = 0; i < n; i++){
		cin >> a[i];
	}

	vector<long long> output;
	for(long long i = n -1; i >= 0; i-=2){
		output.push_back(a[i]);
	}
	long long sIdx = (n % 2);
	for(long long i = sIdx; i < n; i+=2){
		output.push_back(a[i]);
	}

	for(long long i = 0; i < n; i++){
		cout << output[i];
		if(i != n) cout << " ";
	}

	cout << endl;

	return 0;
}