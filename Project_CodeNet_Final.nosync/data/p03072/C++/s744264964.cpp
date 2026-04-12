#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

int main(void) {
    int N;
    cin >> N;
    vector<int> H(N);
    for(int i = 0; i < N; i++ ) {
	cin >> H[i];
    }
    int count = 0;
    for(int i = N; i > 0; i--) {
	int max = 0;
	for(int j = 0; j < i; j++) {
	    if(max < H[j]) max = H[j];
	}
	if(max <= H[i]) count++;
    }
    count++;
    cout << count << endl;
    return 0;
}
