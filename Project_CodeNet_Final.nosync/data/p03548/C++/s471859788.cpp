#include <bits/stdc++.h>
using namespace std;

int main(void){
    int x,y,z;
    cin >> x>>y>>z;
    int cnt=0;
    while(x>=y*cnt+z*(cnt+1)){ cnt++; }
    cout << cnt-1 << endl;
    return 0;
}