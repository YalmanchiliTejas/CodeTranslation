#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <regex>
#include <map>
#include <set>
#include <iomanip>

using namespace std;
using ll = long long;

int main() {
    int X,Y,Z;
    cin >> X >> Y >> Z;
    
    int ans = 0;
    
    for(int i=0;i<X;i++){
        if((Y+Z)*i+Z<=X){
            ans = i;
        }else{
            cout << ans << endl;
            return 0;
        }
    }
    return 0;
}


