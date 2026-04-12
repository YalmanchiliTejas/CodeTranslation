#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n; 
	while( cin >> n, n ){
		vector<int> s(n);
		for(int i=0 ; i < n ; i++ ){
			cin >> s[i];
		}
		sort( s.begin(), s.end() );
		int sum = 0;
		for(int i=1 ; i < s.size()-1 ; i++ ){
			sum += s[i];
		}
		cout << (sum / (s.size() - 2)) << endl;
	}
}