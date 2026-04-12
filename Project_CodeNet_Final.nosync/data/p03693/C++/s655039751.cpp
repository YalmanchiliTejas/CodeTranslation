#include <iostream>

using namespace std;

int main(){
    int r,g,b,ans;
    cin >> r >> g >> b;
    ans = r*100+g*10+b;
    if(ans%4 == 0)cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}