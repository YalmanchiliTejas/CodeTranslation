#include <iostream>

using namespace std;

int main() {

int x,y,z,ans = 0;

cin >> x >> y >> z;

while(1){
    ans++;
    if(y*ans + z*(ans+1) > x) break;
}

cout << ans - 1 << endl;

return 0;
}