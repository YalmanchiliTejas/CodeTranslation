#include <bits/stdc++.h>
using namespace std;
int main(){
    int x,y,z;
    cin>>x>>y>>z;
    int t=x/y;
    while(x-y*t<(t+1)*z)
        t--;
    cout<<t;
}