#include <iostream>
#include <string>    
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
ll n, x[200001], x_sorted[200001];

int main() {
	cin >> n;
	for(ll i = 0; i < n; i++){cin >> x[i]; x_sorted[i] = x[i];}
	sort(x_sorted, x_sorted+n);
	
	for(ll i = 0; i < n; i++){
		if(x[i] < x_sorted[n/2]){cout << x_sorted[n/2] << endl;} 
		else{cout << x_sorted[n/2-1] << endl;}
	}
	
	return 0;
}