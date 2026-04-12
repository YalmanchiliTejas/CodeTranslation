#include <iostream>
#include <cstring>
#include <string>    
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
ll n, a[200008], b[200008], ite;

int main(){
	cin >> n;
	for(ll i = 1; i <= n; i++){cin >> a[i];}
	if(n%2 == 0){
		ite = n/2+1;
		for(ll i = 1; i <= n; i++){
			b[ite] = a[i];
			ite += (i%2 == 0)? i : -i;
		}
	}
	else{
		ite = n/2+1;
		for(ll i = 1; i <= n; i++){
			b[ite] = a[i];
			ite += (i%2 == 0)? -i : i;
		}
	}
	
	for(ll i = 1; i <= n; i++){cout << b[i] << " ";}
	cout << endl;
	return 0;
}