#include<bits/stdc++.h>
using namespace std;
#define int long long
 
signed main(){
	int n, m;
	cin >> n >> m;
	
	vector<int> a(m), b(m);
	for(int i = 0; i < m; i++){
		cin >> a[i] >> b[i];
	}
	
	vector<int> vec(n);
	for(int i = 0; i < n; i++) vec[i] = i + 1;
	int ans = 0;
	do{
		//for(int i = 0; i < n; i++) cout << vec[i];
		//cout << endl;
		
		if(vec[0] != 1) break;
		
		int count = 0;
		for(int i = 0; i < n - 1; i++){
			int tmp = vec[i];
			int tmp1 = vec[i + 1];
			for(int j = 0; j < m; j++){
				if((tmp == a[j] && tmp1 == b[j]) || (tmp == b[j] && tmp1 == a[j])){
					count++;
					break;
				}
			}
		}
		if(count == n - 1){
			ans++;
		}
	}while(next_permutation(vec.begin(), vec.end()));
	
	cout << ans << endl;
}