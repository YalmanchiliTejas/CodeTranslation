#include <iostream>
#include <vector>
using namespace std;

int main() {
    int numElements;
    cin >> numElements;
    vector<long long> sequence(numElements);
    for(int i = 0; i < numElements; i++) {
    	scanf("%lld",&sequence[i]);
    }

    long long memo[numElements][numElements];
    memset(memo, 0, sizeof(memo));

    for(int i = numElements-1; i >= 0; i--) {
        for(int j = i; j < numElements; j++) {
            if(i == j) {
                memo[i][j] = sequence[i];
            } else {
                memo[i][j] = max(sequence[i] - memo[i+1][j], sequence[j] - memo[i][j-1]);
            }
        }
    }
	
	printf("%lld\n",memo[0][numElements-1]);
    
    return 0;
}