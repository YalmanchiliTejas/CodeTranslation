#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(void){
    int x,y,z; cin >> x >> y >> z; x -= z;
    cout << x/(y+z) << endl;
    return 0;
}