#include <bits/stdc++.h>
using namespace std;

int main () {
    int  r, g, b ; 
    cin >> r >> g >> b ;
    int sum=100*r+10*g+b;
    cout <<(((sum)%4==0)?"YES\n":"NO\n");

    return 0;
}
