#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int n;
pair<int,int>a[200001];
int ans[200001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> a[i].first;
		a[i].second=i;
	}
	sort(a+1,a+n+1);
	for(int i=1; i<=n/2 ;i++) ans[a[i].second]=a[n/2+1].first;
	for(int i=n/2+1; i<=n ;i++) ans[a[i].second]=a[n/2].first;
	for(int i=1; i<=n ;i++) cout << ans[i] << endl;
}