#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int n, sum, x;
	while(cin >> n, n){
		vector<int> vec;
		for(int i = 0; i < n; i++){
			cin >> x;
			vec.push_back(x);
		}
		sort(vec.begin(), vec.end());

		sum = 0;
		for(vector<int>::iterator it = vec.begin() + 1; it != vec.end() - 1; it++){
			sum += *it;
		}
		cout << sum / (vec.size() - 2) << endl;
	}
}