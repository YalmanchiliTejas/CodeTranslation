#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
	int mor, aft;
	while(1){
		vector<int> num;
		for(int i = 0; i < 5; i++){
			cin >> mor >> aft;
			if(mor == 0 && aft == 0)goto finished;
			num.push_back(mor + aft);
		}
	
		int ans = 0;
		char shop;
		for(int i = 0; i < 5; i++){
			if(ans < num[i]){
				ans = num[i];
				shop = 'A' + i;
			}
		}
	
		cout << shop << " " << ans << endl;
	}
	finished:
	return 0;
}