#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

	int n,m;
	while(cin>>n>>m && !(n==0&&m==0)){
		vector<int> vec;
		for(int i = 0; i < n+m; i++){
			int tmp;
			cin >> tmp;
			vec.push_back(tmp);
		}
		sort(vec.begin(),vec.end());

		int prvCar=vec[0];
		int empTime=vec[0];
		for(int i = 1; i < vec.size(); i++){
			empTime=max(empTime,vec[i]-prvCar);
			prvCar=vec[i];
		}
		cout << empTime << endl;
	}

	return 0;
}