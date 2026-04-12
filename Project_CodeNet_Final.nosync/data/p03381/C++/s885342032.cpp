#include <iostream>
#include <algorithm>
#include<vector>
#include <queue>
using namespace std;
int h[200005] = { 0 };
int main()
{
	priority_queue<int>pque;
	int n,a;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		pque.push(a);
		h[i] = a;
	}
	for (int i = 1; i <= n / 2 - 1; i++){
		pque.pop();
	}
	int c2 = pque.top();
	pque.pop();
	int c1 = pque.top();
	//cout << c2 << " " << c1 << endl;
	for (int i = 1; i <= n; i++) {
		if(h[i]<=c1) cout<<c2<<endl;
		else cout << c1 << endl;
	}
}
