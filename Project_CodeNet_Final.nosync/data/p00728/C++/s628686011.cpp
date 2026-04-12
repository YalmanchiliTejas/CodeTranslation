#include <iostream>
#include <vector>
#include <algorithm>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef vector<int> vi;

int main(){
	int n;
	while(cin >> n, n){
		vi v(n);
		rep(i, n){
			cin >> v[i];
		}
		sort(all(v));
		int sum = 0;
		for(int i = 1; i < n-1; i++){
			sum += v[i];
		}
		cout << sum/(n-2) << endl;
	}

	return 0;
}