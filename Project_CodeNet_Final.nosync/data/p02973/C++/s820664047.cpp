#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#include<vector>

using namespace std;

#define INF 1000000007
#define LINF 1000000000000000007

typedef long long i64;
typedef pair<i64,i64> P;


int n, a[101010];
int d[101010];

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	for(int i = 0; i <= n; i++) d[i] = -1;
	
	int cnt = 1;
	for(int i = 0; i < n; i++){
		if(i == 0){
			d[n - cnt] = a[i];
			continue;
		}
		if(*(lower_bound(d, d+n, a[i]) - 1) == -1){
			cnt++;
			d[n - cnt] = a[i];
		}
		else{
			*(lower_bound(d, d+n, a[i]) - 1) = a[i];
		}
	}
	
	cout << cnt << endl;
	
	
	
	return 0;
}