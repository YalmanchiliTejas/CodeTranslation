#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;
typedef long long int ll;

int main(){
	int n; cin >> n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	deque<int> b;
	for(int i=0;i<n;i++){
		if(i%2==0) b.push_back(a[i]);
		else b.push_front(a[i]);
	}
	vector<int> c(b.begin(),b.end());
	if(n%2==1) reverse(c.begin(),c.end());
	for(int i=0;i<n;i++){
		cout << c[i] << " " ;
	}
	cout << endl;
}