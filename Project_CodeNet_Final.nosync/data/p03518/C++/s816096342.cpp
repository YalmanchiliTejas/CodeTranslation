#include<bits/stdc++.h>
using namespace std;
const int MaxN = 100005;

int n, i, j, vt;
int pas[MaxN];
vector<int> ans;

main(){
	cin >> n;
	for(i=0;i<n;i++)
		cin >> pas[i];
	for(i=n-1;i>=0;i--){
		for(j=0;j<n;j++){
			if(pas[j]==i){
				vt = j;
				break;
			}
		}
		for(j=0;j<vt;j++)
			ans.push_back(1);
		for(j=vt;j<i;j++){
			ans.push_back(1);
			ans.push_back(n-1);
		}
		for(j=i;j<n;j++)
			ans.push_back(1);
		for(j=vt;j<i;j++)
			swap(pas[j], pas[j+1]);
	}
	cout << ans.size() << endl;
	for(i=0;i<ans.size();i++)
		cout << ans[i] << endl;
}