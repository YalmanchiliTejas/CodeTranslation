#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#include <deque>
using ll = long long;
using namespace std;


int main(){
    int a, b, c;
    cin >> a >> b >> c;
    if((a*100+b*10+c)%4 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
