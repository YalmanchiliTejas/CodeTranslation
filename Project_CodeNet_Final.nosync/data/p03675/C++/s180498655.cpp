#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <deque>
using namespace std;
int main(){
	int n;
	cin >> n;
	deque<int> num;
	deque<int>::iterator pos;
	int d=0,a;
	for (int i=1;i<=n;i++){
		cin >> a;
		if (d==1) { num.push_front(a); d=0; }
			else {num.push_back(a);d=1; }
	}
	if (d==0){
		for (pos=num.begin();pos != num.end();pos++)
			cout << *pos << " ";
	}
		else {
		for (pos=num.end()-1;pos != num.begin()-1;pos--)
			cout << *pos << " ";
		}
	return 0;
}
