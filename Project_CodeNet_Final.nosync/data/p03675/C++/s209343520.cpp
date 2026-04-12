#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
int main(){
	int n;
	deque<int> d;
	cin >> n;
	int inv = 0;
	for(int i=0;i<n;i++){
		int a;
		cin >> a;
		if(inv == 0){
			d.push_back(a);
		}
		else{
			d.push_front(a);
		}
		inv ^= 1;
	}
	if(inv) reverse(d.begin(),d.end());
	for(int i : d) cout << i << " ";
	cout << endl;
	return 0;
}