#include <iostream>
#include <algorithm>

using namespace std;

int n, ans;
int v[100010];
string s;

void tap(int x)
{
	if (x == 2) {
		int c=0;
		for(int i=1; i < n; i++) {
			if(v[i] == 1) {
				if(s[i] == 'o')
					v[i+1] = v[i-1];
				if(s[i] == 'x') {
					if(v[i-1] == 1)
						v[i+1] = 2;
					if(v[i-1] == 2)
						v[i+1] = 1;
				}
			}
			if(v[i] == 2) {
				if(s[i] == 'o') {
					if(v[i-1] == 1)
						v[i+1] = 2;
					if(v[i-1] == 2)
						v[i+1] = 1;
				}
				if(s[i] == 'x')
					v[i+1] = v[i-1];
			}
		}
		for(int i=0; i < n; i++) {
			int a = i-1, b = i+1;
			if(a == -1)
				a = n-1;
			if(b == n)
				b = 0;
			
			if(v[i] == 1) {
				if(s[i] == 'o' && v[a] != v[b])
					c = 1;
				if(s[i] == 'x' && v[a] == v[b])
					c = 1;
			}
			if(v[i] == 2) {
				if(s[i] == 'o' && v[a] == v[b])
					c = 1;
				if(s[i] == 'x' && v[a] != v[b])
					c = 1;
			}
		}
		
		if(c == 0) {
			for(int i=0; i < n; i++) {
				if(v[i] == 1)
					cout << "S";
				else
					cout << "W";
			}
			exit(0);
		}
		return;		
	}
	
	for(int i=1; i <= 2; i++) {
		v[x] = i;
		tap(x+1);
	}
}

int main()
{
	cin >> n >> s;
	
	tap(0);
	cout << -1;
}