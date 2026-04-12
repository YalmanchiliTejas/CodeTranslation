#include <iostream>

using namespace std;

int main(){
    long n; cin >> n;
    long ans = 0;
    long paid = n / 15;
    cout << n*800-paid*200 << endl;
}