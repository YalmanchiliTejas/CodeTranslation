#include <bits/stdc++.h>
using namespace std;
int main(void){
    char a,b,c;
    cin >> a >> b >> c;
    int D = (a - '0')*100 + (b - '0')*10 + (c - '0');
    if(D%4 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
}
