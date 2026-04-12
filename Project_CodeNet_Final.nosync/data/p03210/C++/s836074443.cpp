#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;

typedef long long int ll;
typedef long int li;

int main(void){
    ll a;
    cin >> a;
    if(a==3||a==5||a==7)cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}