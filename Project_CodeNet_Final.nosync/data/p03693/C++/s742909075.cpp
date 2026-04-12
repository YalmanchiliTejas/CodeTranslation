#include <iostream>

using namespace std;
typedef long long ll;

int main(){
    ll r, g, b;
    cin >> r >> g >> b;
    if((100 * r + 10 * g + b) % 4){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }
    return 0;
}
