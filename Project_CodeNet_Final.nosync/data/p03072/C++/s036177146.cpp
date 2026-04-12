#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main(){
	uint16_t N;
	cin >> N;
	uint16_t *H;
	H = new uint16_t[N];

	for(uint16_t i = 0;i < N;++i)
		cin >> H[i];
	uint16_t res = 1;
	uint16_t j = 0;
	for(uint16_t i = 1;i < N;++i){
		for(j = 0;j < i;++j){
			if(H[i] < H[j])
				break;
		}
		if(j == i )
			++res;
	}
	cout << res << endl;

	return 0;
}