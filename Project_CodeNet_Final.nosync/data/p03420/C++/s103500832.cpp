#include <bits/stdc++.h>
using namespace std;
int n,k,l = 0;
long long ans;
int main(){
	//freopen("readin.txt","r",stdin);
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		ans+=n/i*max(0,i - k);
		ans+=max(0,n%i - k + 1);
	}
	cout << ans - (k ? 0 : n) << endl;
}  