#include<bits/stdc++.h>

using ll = long long;
using namespace std;


int main()
{
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    c += c;
    int nax = 1000000000;

    for(int i = 0; i <= 200000; i++){
        int X = max(0,x - i);
        int Y = max(0,y - i);

        int cur = 0;
        cur += i * c;
        cur += X * a + Y * b;
        nax = min(cur,nax);
        //cout << i << " " << X << " " << Y << endl;
    }

    cout << nax << endl;

}