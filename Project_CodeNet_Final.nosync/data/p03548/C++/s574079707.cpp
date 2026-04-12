#include<bits/stdc++.h>
using namespace std;
long long a, b, c, sum;
int main(){ 
    cin >> a >> b >> c;
    sum = (a - c) / (b + c);
    cout << sum;
    return 0;
}