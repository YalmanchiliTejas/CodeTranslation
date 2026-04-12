#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <functional>

using namespace std;

int main() {
    int a,b,c,ans = 0;

    cin >> a >> b >> c;

    while(1){
        a -= c;
        a -= b;

        if(a - c < 0){
            break;
            
        }
        
        ans++;
    }

    cout << ans << endl;
    
  return 0;
}
