#include <iostream>
#include <cmath>

using namespace std;

const int sz = 1000000007;

int main() {
 	int n;
  	cin >> n;
  	long long arr[n];
    long long pref[n];
    
  	for (int i = 0; i < n; i++) {
     	cin >> arr[i];
    }
    
    pref[0] = arr[0];
    for (int i = 1; i < n; i++) {
        pref[i] = pref[i - 1] + arr[i];
    }
  
  	long long sum = 0;
  	for (int i = 1; i < n; i++) {
        sum += (((pref[i - 1] % sz) * (arr[i] % sz)) % sz); 
    }
  
  	cout << sum % sz << endl;
  	return 0;
}