#include <bits/stdc++.h>
using namespace std;
int main(){
    long a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    long long price = a*x + b*y;
    for(long i = 0; i <= max(x,y); i++){
        long long tmpPrice = 2*i*c + max(a*(x-i),0L) + max(b*(y-i),0L);
        //long long tmpPrice = 2*i*c;
        //tmpPrice += max(a*(x-i),0L);

        price = min(tmpPrice,price);
    }
    cout << price << endl;
    return 0;
}