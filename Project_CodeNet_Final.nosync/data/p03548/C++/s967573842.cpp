#include<bits/stdc++.h>
using namespace std;
int main(){
    
    int x,y,z,a=1;
    
    cin >> x >> y >> z;
    x-=(y+z+z);
    while(1){
        x-=(y+z);
        if (x<0){
            break;
        }
        a++;



    }
    cout << a << endl;
}
