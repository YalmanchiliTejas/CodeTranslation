#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
#include <string>
typedef long long ll;

using namespace std;

int main(){
    int X, Y, Z;
    cin >> X >> Y >> Z;

    int len = Z;
    int res = 0;
    while (len+Y+Z <= X){
	res++;
	len += Y+Z;
    }

    cout << res << endl;

    return 0;
}
