#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <functional>
 
using namespace std;
 
int main(void) {
	unsigned long int N, num = 1;
	unsigned long int H[101];
	cin >> N;
	for(int i = 0 ; i < N ; i++){
	    cin >> H[i];
	}
	
	for(int i = 1 ; i < N ; i++){
	    for(int j = 0 ; j < i ; j++){
	        if(H[j] > H[i]){
	            break;
	        }
	        if(j == i-1){
	            num++;
	        }
	    }
	}

    cout << num;
	return 0;
}