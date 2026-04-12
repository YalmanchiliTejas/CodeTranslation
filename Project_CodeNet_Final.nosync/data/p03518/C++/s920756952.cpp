/*
 _   ________   ___       __ ___   _           _  _
| | / /|  _  \ / _ \     / // _ \ | |         | |(_)
| |/ / | | | |/ /_\ \   / // /_\ \| | __ __ _ | | _
|    \ | | | ||  _  |  / / |  _  || |/ // _` || || |
| |\  \| |/ / | | | | / /  | | | ||   <| (_| || || |
\_| \_/|___/  \_| |_//_/   \_| |_/|_|\_\\__,_||_||_|
*/
#include<bits/stdc++.h>
using namespace std;
int n,a[205];
vector<int> ans;
int main(){
	cin >> n;
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<n;i++){
		for(int j=1;j<n;j++){
			ans.push_back(1);
			for(int i=1;i<n;i++) swap(a[i],a[i-1]);
			if(a[0]<a[n-1]){
				ans.push_back(n-1);
				swap(a[n-1],a[0]);
			}
		}
		ans.push_back(1);
		for(int i=1;i<n;i++) swap(a[i],a[i-1]);
	}
	cout << ans.size() << '\n';
	for(int i=0;i<ans.size();i++) cout << ans[i] << '\n';
}