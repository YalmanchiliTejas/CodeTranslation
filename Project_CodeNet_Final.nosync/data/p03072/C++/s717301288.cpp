#include"bits/stdc++.h"
using namespace std;
int main(){
	int ans = 0, n, cur_max = 0;
	cin >> n;
	
	for(int i = 0; i != n; ++i){

		int temp;
		cin >> temp;
		cur_max = max(cur_max, temp);

		if(temp >= cur_max)
			++ans;
	}

	cout << ans;
}
 




