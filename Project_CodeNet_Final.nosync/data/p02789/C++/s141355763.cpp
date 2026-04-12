#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <bitset>
#include <queue>
#include <utility>
#include <functional>
#include <sstream>
using namespace std;
#define ll long long
 
int main(void){
    ll n, m;
    cin >> n >> m;
    if(n==m)
        cout << "Yes" << endl;
    else if(n > m)
        cout << "No" << endl;
    return 0;
}