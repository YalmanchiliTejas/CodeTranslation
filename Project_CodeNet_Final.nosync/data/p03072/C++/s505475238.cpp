#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int n, higher, temp, res=1;
	cin >> n >> higher;

	for(int i = 0; i < n-1; i++){
		cin >> temp;
		if(temp >= higher){
			res++;
			higher = temp;
		}
	}
	cout << res << endl;
	return 0;
}