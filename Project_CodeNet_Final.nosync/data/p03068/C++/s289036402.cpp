#include<bits/stdc++.h>

#define  SZ(items) (int)items.size()
#define  CLR(a)  memset(a,0,sizeof(a))
#define  SET(a)  memset(a,-1,sizeof(a))


int dx[] = { 0,0,1,-1,-1,-1,1,1 };
int dy[] = { 1,-1,0,0,-1,1,1,-1 };

template <class T> inline T gcd(T a, T b) { while (b) { a = a%b; swap(a, b); } return a; }

using namespace std;


int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;

	int k;
	cin >> k;

	for (int i = 0; i < n; i++) {
		if (s[k - 1] != s[i]) {
			s[i] = '*';
		}
		cout << s[i];
	}
	cout << endl;



	return 0;
}