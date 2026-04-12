#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int x,y,z;
    cin>>x>>y>>z;
    x-=z;
    cout<<x/(y+z)<<endl;
    return 0;
}