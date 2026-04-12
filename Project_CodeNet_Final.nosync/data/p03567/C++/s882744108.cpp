#include <bits/stdc++.h>

#define pout(n)  printf ("%d\n", n)

#define rep(i,a,n) for (int i = a;i < n;i++)
#define per(i,n,a) for (int i = n-1;i >= a;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());

const int d4x[4] = {1, 0, -1, 0};
const int d4y[4] = {0, 1, 0, -1};
const int d8x[8] = { 1,1,0,-1,-1,-1,0,1 };
const int d8y[8] = { 0,1,1,1,0,-1,-1,-1 };

#define MAX_N (int)2e5+20
#define INF 1e12+20

typedef long long ll;
using namespace std;

string s;
int main() {
	cin >> s;

	bool ans = false;
	rep(i,0,s.size()-1){
		if(s[i] == 'A'){
			if(s[i+1] == 'C'){
					ans = true;
				}
				
			}	
	}
	if(ans == true) printf("Yes\n");
	else printf("No\n");
	return 0;
}