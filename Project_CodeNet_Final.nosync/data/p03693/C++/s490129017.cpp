#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

using ll = long long int;

int main(){
    
    ll R, G, B;
    
    cin >> R >> G >> B;
    
    if((R * 100 + G * 10 + B) % 4 == 0){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}