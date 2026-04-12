#include <bits/stdc++.h>
#define pb push_back
#define pf push_front

using namespace std;

int main(){
	int n;
	deque<int> dq;
	cin >> n;
	for(int i=0; i<n; i++){
		int a; cin >> a;
		if(i%2) dq.pb(a);
		else dq.pf(a);
	}
	if(n%2 == 0) reverse(dq.begin(),dq.end());
	for(int i:dq) cout << i << " ";
}
