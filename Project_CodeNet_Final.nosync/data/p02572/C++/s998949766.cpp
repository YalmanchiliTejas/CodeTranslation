#include <iostream>
using namespace std;

int main(void){

    int n;
    long long int a[200000];

    int i, j;

    unsigned long long int total, ans, mul;

    total = 0;
    ans = 0;

    cin >> n;
    for(i=0;i<n;i++){
        cin >> a[i];
        total += a[i];
    }

    for(i=0;i<n;i++){
        total -= a[i];
        mul = (total % 1000000007);
        ans += a[i] * mul;
        ans = (ans % 1000000007);
    }

    cout << (ans % 1000000007);

    return 0;

}