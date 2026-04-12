#include <bits/stdc++.h>
using namespace std;

int main() {
long long x,y,z;
cin >> x >> y >> z;
int ans=0;
for(int i=1;i<50000;i++){
    long long dist=y*i+z*(i+1);
    if(dist<=x)ans=i;
}
cout << ans;
}
