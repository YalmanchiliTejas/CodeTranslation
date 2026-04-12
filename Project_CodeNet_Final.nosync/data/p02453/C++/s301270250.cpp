#include<iostream>
#include<algorithm>
using namespace std;
static const int MAX_N = 100000;

int n, a[MAX_N];
int q, k;

int main(){
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	cin >> q;
	for(int i = 0; i < q; i++){
		cin >> k;
		cout << lower_bound(a, a + n, k) - a << endl;
	}
	return 0;
}

