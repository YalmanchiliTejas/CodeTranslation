#include <stdio.h>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main(void){
    int a,b,c;
    cin >> a >> b >> c;
    string ans = ((100*a+10*b+c)%4)==0?"YES":"NO";
    cout << ans << endl;
    return 0;
}