#include <iostream>

using namespace std;

#define min(a, b) ((a)<(b)? (a):(b))
#define max(a, b) ((a)>(b)? (a):(b))

int main() {
	while(true) {
        int n; cin >> n;
        if(n == 0) break;
	    int sum = 0, s_min = 1024, s_max = -1;
	    for(int i=0; i<n; i++) {
	        int s; cin >> s;
	        sum += s;
	        s_min = min(s_min, s);
	        s_max = max(s_max, s);
	    }
	    cout << (sum - s_min - s_max) / (n - 2) << endl;
	}
}

