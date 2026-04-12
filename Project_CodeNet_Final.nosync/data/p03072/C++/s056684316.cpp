#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ed cout<<"\n";
using namespace std;

int main() {
  speed;
	int n;
	int h[20];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	int ans=1;
	for (int i = 1; i < n; i++) {
		int count = 0;
		for (int j = i-1; j >= 0; j--) {
			if (h[i] - h[j] >= 0)count++;
          else{
            count=0;
            break;
          }
		}
		if (count >0 )ans++;
	}
		cout << ans ;
  ed;
	return 0;
}
