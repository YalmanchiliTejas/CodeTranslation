#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int n;
	while( cin >> n, n ){
		vector<int> v(n);
		for(int i=0; i<n; i++)
			cin >> v[i];
		sort( v.begin(), v.end() );
		int res = 0;
		for(int i=1; i<n-1; i++)
			res += v[i];
		cout << res/(n-2) << endl;
	}
	return 0;
}