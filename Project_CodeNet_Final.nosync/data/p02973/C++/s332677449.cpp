#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main() {
	int n,p,k = 0,tmp;
	cin >> n;
	while (n--){
		cin >> p;
		tmp = upper_bound(a,a + k,p,greater< int >()) - a;
		if (tmp == k){
			a[k] = p;
			++ k;
		}
		else a[tmp] = p;
	}
	cout << k << endl;
}