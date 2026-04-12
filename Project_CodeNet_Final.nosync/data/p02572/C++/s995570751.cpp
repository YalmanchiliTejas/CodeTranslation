#include <bits/stdc++.h>
using namespace std;
const int M=1e9+7;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	int a[n];
	long long sum=0;
	for(int i=0; i<n; i++) cin >> a[i], sum+=a[i];
	long long res=0;
	long long temp=0;
	for(int i=0; i<n; i++){
		temp+=a[i];
		(res+=1ll*a[i]*((sum-temp)%M)%M)%=M;
	}
	cout << res;
}