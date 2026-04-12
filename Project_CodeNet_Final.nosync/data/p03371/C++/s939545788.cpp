#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	
    ll a, b, c, x, y; cin >> a >> b >> c >> x >> y;
    c *= 2;
    ll sum = 0;
    if(c <= a+b){
        sum += min(x,y)*c;
        ll aux = min(x,y);
        x -= aux; y -= aux;
        if(c < a) sum += x*c;
        else sum += x*a;

        if(c < b) sum += y*c;
        else sum += y*b;
    }
    else sum += x*a+y*b;
    cout << sum << endl;
	return 0;
}
