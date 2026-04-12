#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	double res;
	for(int n; cin >> n, n; cout << (int)res << endl){
		res = 0.0;
		vector<int> l;
		for(int i = 0; i < n; i++){
			int buf; cin >> buf;
			l.push_back(buf);	
		}
		sort(l.begin(), l.end());
		for(int i = 1; i < l.size() - 1; i++){res += (double)l[i];}
		res /= (double)(l.size() - 2);
	}
	return 0;
}