#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <numeric>
#include <cstdlib>
#include <map>
#include <algorithm>

using namespace std;

int main(){
    int X,Y,Z;

    cin >> X >> Y >> Z;

    int num = 0;

    while((Y+Z)*num <= (X-Z)){
        num++;
    }

    cout << num-1 << endl;

    return 0;
}