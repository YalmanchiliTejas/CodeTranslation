#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
int s[100];
vector<int> aans;

int main(){
	while(1){
		int ans = 0;
		cin >> n;
		if(n == 0) break;
		for(int i = 0;i < n;i++){
			cin >> s[i];
		}
		sort(s,s+n);
		for(int i = 1;i < n-1;i++){
			ans += s[i];
		}
		
		ans /= n-2;
		
		aans.push_back(ans);
	}
	for(int i = 0;i < aans.size();i++){
		cout << aans[i] << endl;
	}
}