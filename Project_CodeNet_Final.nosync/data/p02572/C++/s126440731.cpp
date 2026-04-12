#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <map>
#include <list>
 
using namespace std;

const int MOD = 1000000007;

int main() {
	int n;
	long long sum = 0;
	cin >> n;
    long long arr[n+1];
    long long arrsum = 0;
	
    for(int i=0; i<n; i++){
        long long num;
        cin >> num;
        arr[i] = num;
        arrsum += num;
    }
    
    for(int i=0; i<n-1; i++){
        arrsum -= arr[i];
        int arrsummod = arrsum % MOD;
        int result = arr[i] * arrsummod % MOD;
        sum += result;
        sum %= MOD;
    }
    cout << sum % MOD << endl;
	return 0;
}