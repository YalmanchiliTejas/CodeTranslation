#include <bits/stdc++.h>
using namespace std;

int main(){
    int r,g,b;
    cin >> r >> g >> b;
    int Q;
    Q = 10*g + b;
    if(Q%4 == 0) cout << "YES" << endl;
    else cout <<"NO"<<endl;
}