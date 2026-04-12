#include<bits/stdc++.h>
 
using namespace std;
 
#define INF 1000000007
#define LINF 1000000000000000007
 
typedef long long i64;
typedef pair<i64,i64> P;


int n, a[101];

int main(){
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	
	int cnt = 0, m = 0;
	for(int i = 0; i < n; i++){
		m = max(m, a[i]);
		if(m <= a[i]) cnt++;
	}
	cout << cnt << endl;
	
	return 0;
}