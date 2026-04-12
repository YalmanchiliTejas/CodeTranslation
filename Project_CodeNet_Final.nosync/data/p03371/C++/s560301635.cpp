#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a,b,c;
    cin >> a >> b >> c;
    long long x,y;
    cin >> x >> y;
    if(x<y){
        swap(a,b);
        swap(x,y);
    }
   
    cout << y*min(a+b,2*c)+(x-y)*min(a,2*c) << endl;

}