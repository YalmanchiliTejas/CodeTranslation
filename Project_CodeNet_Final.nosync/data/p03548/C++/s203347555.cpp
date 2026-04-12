#include <bits/stdc++.h>
using namespace std;

int main() {
    int x,y,z;
    cin >> x >> y >> z;
    int ans=0;
    while(true){
        if(ans*y+ans*z+z>x){
            break;
        }
        ans+=1;
    } 
    cout <<ans -1<< endl;

    return 0;
}
