#include<iostream>
using namespace std;

int main() {
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
		cout << ans << endl;
	return 0;
}
