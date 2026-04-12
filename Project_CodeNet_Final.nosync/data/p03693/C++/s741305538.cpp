#include <bits/stdc++.h>
using namespace std;
int main(){
    int  a, b ,c;
    char X,Y;
    string S1,S2;
    cin >>a >> b >> c;
    if((100*a+10*b+c)%2 == 0 && ((100*a+10*b+c)/2)%2 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
}
