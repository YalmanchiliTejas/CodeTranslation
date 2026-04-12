#include <iostream>
#include <cmath>

using namespace std;

long long a,b,c,x,y;

int main(){
    cin >> a >> b >> c >> x >> y;
    long long n = x * a + y * b;
    long long m = min(x,y) * c * 2;
    if(x > y){
        m += (x-y) * a;
    }else{
        m += (y-x) * b;
    }
    long long o = max(x,y) * c * 2;
    cout << min(min(m,n),o) << endl;
    return 0;
}