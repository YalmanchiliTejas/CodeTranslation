#include <iostream>
#include <string>
//#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int X, Y, Z;
    cin >> X >> Y >> Z;

    int nokori = X - 2*Z;

    int a = nokori/(Y+Z);
    int mod = nokori%(Y+Z);

    if(mod >= Y){
        a++;
    }

    cout << a << endl;

    return 0;
}
