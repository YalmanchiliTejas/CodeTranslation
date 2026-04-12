#include <iostream>
#include <array>
using namespace std;

int main() {
	array<int,3> value;
	
	for(int i=0;i<3;++i){
		int tmp;
		cin >> tmp;
		value[i]=tmp;
	}
	
	int answer = value[0]*100+value[1]*10+value[2];
	
	if(answer%4==0) cout << "YES" << endl;
	else cout << "NO" << endl;
	
	return 0;
}