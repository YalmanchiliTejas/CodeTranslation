#include<bits/stdc++.h>
using namespace std;
int main(){

    int a, b, c; cin >> a >> b >> c;

    int r = a/(b+c);
    int m = a%(b+c);

    if( m >= c ){
        cout << r << '\n';
    }else{
        cout << r-1 << '\n';
    }

}
