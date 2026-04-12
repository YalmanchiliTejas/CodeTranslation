#include<bits/stdc++.h>
using namespace std;
int main(){
    int a, b, c;
    cin >> a >> b >> c;
    int num;
    num = 100*a+10*b+c;
    if(num%4==0) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}


