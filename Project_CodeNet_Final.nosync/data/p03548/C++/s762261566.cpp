#include<bits/stdc++.h>
using namespace std;

int main(){
    int x,y,z; cin >> x >> y >> z;
    int p = 0;
    int ans;
    while(y*p +z*(p+1) <= x){
        ans = p;
        p++;
    }
    cout << p-1 << endl;
}


