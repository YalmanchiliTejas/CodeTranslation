/* -- 2406:Al dente -- */
#include	<iostream>

using namespace std;

int main(void) {
	int N, T, E, x, ans = -1;

	cin >> N >> T >> E;
	for(int i=0; i<N; i++) {
		cin >> x;
		if(ans == -1 && (T+E)%x <= E ) { ans = i+1; }
	}
	cout << ans << endl;
}