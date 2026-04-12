// luogu-judger-enable-o2
#include <bits/stdc++.h>
using namespace std;

int a[100005];

int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	s = s + s;
	for(int i1 = 0;i1 < 2;i1++)
		for(int i2 = 0;i2 < 2;i2++){
			a[0] = i1;
			a[1] = i2;
			for(int i = 2;i <= n + 1;i++){
				if(s[i - 1] == 'o' && a[i - 1] == 0)
					a[i] = 1 - a[i - 2];
				if(s[i - 1] == 'o' && a[i - 1] == 1)
					a[i] = a[i - 2];
				if(s[i - 1] == 'x' && a[i - 1] == 0)
					a[i] = a[i - 2];
				if(s[i - 1] == 'x' && a[i - 1] == 1)
					a[i] = 1 - a[i - 2];
			}
			if(a[n] == a[0] && a[n + 1] == a[1]){
				for(int i = 0;i < n;i++)
					cout << (a[i] ? 'S' : 'W');
				return 0;
			}
		}
	cout << -1;
	return 0;
}