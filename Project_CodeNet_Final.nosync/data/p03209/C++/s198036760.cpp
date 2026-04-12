#include <iostream>
using namespace std;
long long g(long long l){
    return ((long long)1 << (l+2)) - 3;
}
long long h(long long l){
    return ((long long)1 << (l+1)) - 1;
}
long long f(long long n, long long x){
    long long r = 0, y = x;
    if(x <= 1)return 0;
    if(x == 1)return 1;
    if(x >= g(n)-1)return h(n);
    if(x >= g(n-1)+2){
        r = 1;
        r += h(n-1);
        r += f(n-1, x-g(n-1)-2);
    }else if(x == g(n-1)+1){
        r = h(n-1);
    }else{
        r = f(n-1, x-1);
    }
    return r;
}
int main() {
    long long n, x;
    cin >> n >> x;
    cout << f(n, x) << endl;
	return 0;
}