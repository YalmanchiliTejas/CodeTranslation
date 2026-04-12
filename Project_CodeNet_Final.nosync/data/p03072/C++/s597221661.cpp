#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n,ans,high;
	cin >> n;
	vector<int> m(n);
	for (int i = 0; i < n; i++){
		cin >> m.at(i);
	}

	for (int i = 0; i < n; i++){
		if (i == 0){
			ans = 1;
			high = m.at(i);
			continue;
		}
		else{
			if (m.at(i) >= high){
				ans++;
				high = m.at(i);
			}
		}
	}

	cout << ans << endl;


	system("pause");
	return 0;
}