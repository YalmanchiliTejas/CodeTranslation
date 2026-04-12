#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int x,y,z;
	cin >> x >> y >> z;
	int sum = x - z*2;
	
	int count = 0;
	while(true){
		sum -= y;
		if(sum < 0)break;
		count++;
		sum -= z;
	}
	
	cout << count << endl;
	return 0;
}