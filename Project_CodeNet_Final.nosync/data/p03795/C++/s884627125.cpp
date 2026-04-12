#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main(){
	int N;
	cin >> N;
	int cnt1=0;
	int cnt2=0;
	cnt1=N*800;
	cnt2=N/15*200;
	cout << cnt1-cnt2 << endl;
	return 0;
}