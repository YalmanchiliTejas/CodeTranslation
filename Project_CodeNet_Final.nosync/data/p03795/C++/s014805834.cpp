#include<bits/stdc++.h>
using namespace std;
    
int main() {
    int n;
    cin >> n;
    int sum = n * 800;
    sum -= (n / 15) * 200;
    cout << sum;
    return 0;
}