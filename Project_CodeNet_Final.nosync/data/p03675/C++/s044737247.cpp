#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	bool rev = false;
	deque<int> dq;
	for(int i = 0;i < n;i++){
		if(rev){
			dq.push_front(a[i]);
		}
		else{
			dq.push_back(a[i]);
		}
		rev ^= true;
	}
	for(int i = 0;i < n;i++){
		cout << dq[!rev ? i : n - 1 - i] << " \n"[i + 1 == n];
	}
	return 0;
}
