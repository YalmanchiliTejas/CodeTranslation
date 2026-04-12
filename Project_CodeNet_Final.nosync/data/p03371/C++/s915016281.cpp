#include <iostream>
#include<cmath>
 using namespace std;
 
int main() {
    long a, b, c, x, y;
 
    cin >> a >> b >> c >> x >> y;
 
    long maxI = max(x, y);
    long minPrice = NULL;
 
    for (long i = 0; i < maxI+1; ++i) {
        long price = i*2*c + max((long)0, x-i) *a + max((long)0, y-i)*b;
 
        minPrice = minPrice == NULL or minPrice > price ? price : minPrice;
    }
 
    cout << minPrice << std::endl;
 
    return 0;
}