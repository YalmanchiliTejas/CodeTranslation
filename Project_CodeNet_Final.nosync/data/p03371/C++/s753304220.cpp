#include <iostream>
#define rep(i, n)for(int i=0; i<n; i++)
using namespace std;
using ll = long long;

int main(){
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int sum = 1000000000;
    for(int i=0; ;i+=2){
        int j, k;
        if(x-i/2>=0) j = x-i/2;
        if(y-i/2>=0) k = y-i/2;
        int cursum = a*j + b*k + c*i;
        if(cursum<sum) sum = cursum;
        if(i/2>x && i/2>y) break;
    }

    cout << sum << endl;

    return 0;
}
