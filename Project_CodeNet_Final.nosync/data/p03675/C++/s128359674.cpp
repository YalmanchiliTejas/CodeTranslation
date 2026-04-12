#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <numeric>
#include <queue>
#include <map> 
#include <set>
#include <string>
#include <functional>
using namespace std;



int main(){

	int n;
	//even,oddは1オリジン
	vector<int> a,ans,even,odd;
	cin >> n;
	for (int i = 0; i < n; i++){
		int tnp;
		cin >> tnp;
		a.push_back(tnp);
		if (i % 2 == 1) even.push_back(tnp);
		else odd.push_back(tnp);
	}


	if (n % 2 == 0){
		reverse(even.begin(), even.end());
		for (size_t i = 0; i < even.size(); i++){
			ans.push_back(even[i]);
		}
		for (size_t i = 0; i < odd.size(); i++){
			ans.push_back(odd[i]);
		}
	}
	else{
		reverse(odd.begin(), odd.end());
		for (size_t i = 0; i < odd.size(); i++){
			ans.push_back(odd[i]);
		}
		for (size_t i = 0; i < even.size(); i++){
			ans.push_back(even[i]);
		}
	}
	for (int i = 0; i < n; i++){
		cout << ans[i] << " ";
	}
	

	return 0;
}