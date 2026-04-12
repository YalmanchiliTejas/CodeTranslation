#include<bits/stdc++.h>
using namespace std;
int main(){
	long long a, b, c, sum;
    cin >> a >> b >> c;
    sum = (a - c) / (b + c);
    cout << sum;
    return 0;
}