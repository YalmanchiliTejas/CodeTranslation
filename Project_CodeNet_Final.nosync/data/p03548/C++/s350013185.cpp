#include <iostream>
#include <algorithm>

using namespace std;
int main() {
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    int x,y,z;
    cin>>x>>y>>z;
    x-=z;
    cout<<x/(y+z);
    return 0;
}