#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<lint, int> pi;
const int MAXN = 205;

int n, a[MAXN];

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	vector<int> ans;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			ans.push_back(1);
			if(j + 1 < n && a[j] > a[j+1]){
				swap(a[j], a[j+1]);
				ans.push_back(n - 1);
			}
		}
	}
	printf("%d\n", ans.size());
	for(auto &i : ans) printf("%d\n", i);
}
