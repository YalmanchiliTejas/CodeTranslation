#include <bits/stdc++.h>
using namespace std;

int main() {
int x,y,z;
cin >> x >> y >> z;

if((x*100+y*10+z)%4==0){
    cout << "YES"; return 0;
}
cout << "NO";
return 0;
}