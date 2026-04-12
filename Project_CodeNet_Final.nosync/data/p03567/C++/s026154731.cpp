#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000000;
char a[maxn];
int main(){
	scanf("%s", a + 1);
	int n = strlen(a + 1);
	for (int i = 1; i <= n - 1; ++i) if (a[i] == 'A' && a[i + 1] == 'C'){
		cout << "Yes" << endl;
		return 0;
	}
	cout << "No" << endl;
	return 0;
}