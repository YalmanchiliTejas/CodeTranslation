#include <iostream>
int main(){
    using namespace std;
    int a,x,y,z,ans;
    cin >> x >> y >> z;
    a = x/(y+z);
    if(x>=a*(y+z)+z){
        ans = (x-(x%(y+z)))/(y+z);
    }else{
        ans = x/(y+z) - 1;
    }
    cout << ans << endl;
    return 0;
}