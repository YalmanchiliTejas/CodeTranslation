#include <bits/stdc++.h>
using namespace std;

#define max(a,b) (((a) < (b)) ? (b) : (a))
int main(void) {
    int64_t A,B,C,X,Y;
    int64_t sum,minsum = LONG_MAX;
    cin >> A >> B >> C >> X >> Y;
    
    for(int i=0;i<=100000;i++) {
        sum = (2 * C * i) + (max(X-i,0) * A) + (max(Y-i,0) * B);
        if(minsum > sum) {
            minsum = sum;
        }
    }

    cout << minsum << "\n";
    return 0;
}
