#include <iostream>
using namespace std;
int main(void){
    long long a, b, x;
    cin >> a >> b >> x;
    long long c = max(0ll, x - b) / (a - b);  //0もlong long型であるからllをつける
    x %= 1000000007;
    c %= 1000000007;
    b %= 1000000007;
    cout << (b * c + x) % 1000000007 << endl;
}

