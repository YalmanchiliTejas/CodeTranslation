#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <numeric>
#include <math.h>
using namespace std;

#define N_MAX   (100000)
#define LL_MAX_NUM (1LL<<60)

typedef long long ll;
typedef long long int lli;

int main() {
    int A, B, C ,X, Y, res;
    cin >> A >> B >> C >> X >> Y;
    res = 0;
    if (X >= 1 && Y >= 1) {
        if (A + B > C*2) {
            int minNum = min(X, Y);
            X = X - minNum;
            Y = Y - minNum;
            int res1 = C*minNum*2+A*X+B*Y;
            int res2 = C*minNum*2+C*X*2+C*Y*2;
            res = min(res1, res2); 
        } else {
            res = A*X+B*Y;
        }
    } 
    
    cout << res << endl;
	return 0;
}
