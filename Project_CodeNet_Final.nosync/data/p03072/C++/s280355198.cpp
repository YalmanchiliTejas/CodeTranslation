#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=int(a); i < int(b); i++)
#define foro(i,a,b) for(int i=int(a); i >= int(b); i--)
#define prnt(a) cout << a << endl

typedef long long int ll;

using namespace std;

int main() {
	int n; cin >> n;
	
	int h[n];
	fore(i,0,n) cin >> h[i];
	
	int ans = 0;
	fore(i,0,n) {
		bool s = true;
		
		fore(j,0,i) if (h[j] > h[i]) {
				s = false;
				break;
			}
		
		if (s == true) ans++;
	}
	
	prnt(ans);

	return 0;
}
