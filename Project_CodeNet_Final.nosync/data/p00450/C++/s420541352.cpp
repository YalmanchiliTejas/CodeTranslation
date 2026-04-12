#include <iostream>
using namespace std;

#define repi(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) for(int i=0;i<(n);i++)

int n;
bool c[100000];

int main() {
	ios::sync_with_stdio(false);
	
	while(cin >> n, n) {
		rep(i, n) cin >> c[i];
		rep(i, n/2) {
			if(c[2*i] ^ c[2*i+1]) {
				int j=2*i;
				while(j>=0 && c[j] ^ c[2*i+1]) {
					c[j] = c[2*i+1];
					j--;
				}
			}
		}
		int r = 0;
		rep(i, n) {
			if(!c[i])r++;
		}
		cout << r << endl;
	}
	
	return 0;
}