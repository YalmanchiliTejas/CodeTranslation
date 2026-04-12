#include<iostream>
using namespace std;

int main(){
    int x, y, z;
    cin >> x >> y >> z;

    int ans = 0;

    x -= z;

    while(1){
        if(x < 0){
            ans--;
            break;
        }

        x -= y + z;
        ans++;
    }

    cout << ans << endl;
}