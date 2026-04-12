#include<iostream>
#include<cstring>
#include<string>
#include <bitset>
#include <type_traits>
#include <string>
#include <climits>
#include <cmath>



using namespace std;

// long long func(long long a, long long b, long long c){ 
//     long long ret = 0;
//     a %= c; 
//     while (b) { 
//         if (b & 1){
//         	ret = (ret + a) % c; 
//         }  
//         a = (2 * a)%c; 
//         b >>= 1;
//     } 
//     return ret; 
// } 

int main(){
	#ifndef ONLINE_JUDGE
	    // for getting input from input.txt
	    freopen("input.txt", "r", stdin);
	    // for writing output to output.txt
	    freopen("output.txt", "w", stdout);
	#endif

	int n, flag;
	long long summy=0;
	long long som=0;
	long long bruh = pow(10,9)+7;
	cin >> n;
	long long arr [n];

	for(int i=0;i<n;i++){
		cin >> arr[i];
	}

	for(int j=1;j<n;j++){
		som += arr[j-1];
		// cout << som << endl;
		// summy += func(som, arr[j], bruh);
		summy += som%bruh * (arr[j]%bruh);
		summy = summy % bruh;
	}

	cout << summy << endl;

	return 0;
}