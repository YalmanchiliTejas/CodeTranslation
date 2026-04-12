#include <iostream>
using namespace std;
int main(){
    int x,y,z,ans;
    cin>> x;
    cin >> y;
    cin >> z;
    x -=z;
    ans = x/(y+z);
    cout << ans;

}
