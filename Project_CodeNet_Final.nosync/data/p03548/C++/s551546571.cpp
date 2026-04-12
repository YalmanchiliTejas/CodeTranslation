#include<iostream>
using namespace std;
int a,b,c,x;
int main (void) {
    cin >> a >> b >> c;
    while (b*x + c*x+c <= a) {
        x++;
    }
    cout << x-1;
    return 0;
}