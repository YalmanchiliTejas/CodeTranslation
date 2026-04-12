#include<iostream>
using namespace std;

int main(void)
{
    int n = 0,tmp = 0;
    cin >> n;
    tmp = n / 15;
    cout << n * 800 - tmp * 200 << endl;
    return 0;
}