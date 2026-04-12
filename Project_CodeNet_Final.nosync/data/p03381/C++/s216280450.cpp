#include<iostream>
#include<string>
#include<algorithm>    
#include<cmath>
#include<map>
#include<vector>
#include<math.h>
#include<stdio.h>
#define int long long
using namespace std;
int test[213456], uiop[213456];
signed main() {
	int n, a; cin >> n;
	for (int h = 0; h < n; h++) {
		cin >> a;
        test[h] = a; uiop[h] = a;
	}
    sort(uiop,uiop + n);
	for (int h = 0; h < n; h++) {
      	if(test[h] <= uiop[n / 2 - 1]){
            cout << uiop[n / 2] << endl;
        }
        else{
        	cout << uiop[n / 2 - 1] <<endl;
     	}
    }
}