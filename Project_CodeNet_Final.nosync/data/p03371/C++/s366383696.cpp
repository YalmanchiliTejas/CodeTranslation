#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    long long a, b, c, x ,y;
    cin >> a >> b >> c >> x >> y;
    vector<long long> z(3);
    z[0] = 2 * c * max(x,y);
    z[1] = a*x + b*y;
    if(x >= y)
        z[2] = 2*c*y + a*(x-y);
    
    else
        z[2] = 2*c*x + b*(y-x);

    sort(z.begin(),z.end());

    cout << z[0] << endl;
    
}