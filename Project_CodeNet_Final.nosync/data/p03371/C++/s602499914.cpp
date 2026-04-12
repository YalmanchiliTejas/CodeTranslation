#include <iostream>
#include <algorithm>


using namespace std;

int main()  {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    long long min_val = 999999999999;
    int val = 0;

    for(int i = 0; i <= 100000; i++) {
        val = (A*max(0, X-i)) + (B*max(0, Y-i)) + (i*2*C);
        if(min_val > val) min_val = val;
    }

    cout << min_val << endl;

    return 0;

}