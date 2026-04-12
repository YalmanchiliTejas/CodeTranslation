#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
	int n, s, sum, maxs, mins, i;
	while((cin >> n), n){
		sum = maxs = 0;
		mins = 1000;
		for(i = 0; i < n; i++){
			cin >> s;
			sum += s;
			maxs = max(maxs, s);
			mins = min(mins, s);
		}
		sum = (sum - maxs - mins) / (n - 2);
		cout << sum << endl;
	}
}