#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int n;
	int h;
	int hmax = 0;
	int count = 0;
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> h;
		if(h >= hmax){
			count++;
		}
		hmax = max(hmax, h);
	}
	cout << count << endl;
}
