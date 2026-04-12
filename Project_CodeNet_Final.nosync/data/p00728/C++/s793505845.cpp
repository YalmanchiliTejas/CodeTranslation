#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
	int n, max, min, s, t;
	
	while(1){
		cin >> n;
		if(n == 0){
			break;
		}
		min = 1001;
		max = s = 0;
		for(int i = 0; i < n; i++){
			cin >> t;
			if(t < min){
				min = t;
			}
			if(max < t){
				max = t;
			}
			s += t;
		}
		
		cout << (s-min-max)/(n-2) << endl;
	}
	
	return 0;
}