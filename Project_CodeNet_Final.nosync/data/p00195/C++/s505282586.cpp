#include<bits/stdc++.h>
#define rep(i,n)for(int i=0;i<n;i++)
using namespace std;

int a[5];
int main() {
	while (1) {
		rep(i, 5) {
			int s1, s2; cin >> s1 >> s2;
			if (s1 == 0 && s2 == 0)return 0;
			a[i] = s1 + s2;
		}
		int*ans = max_element(a, a + 5);
		cout << (char)(ans - a + 'A') << ' ' << *ans << endl;
	}
}