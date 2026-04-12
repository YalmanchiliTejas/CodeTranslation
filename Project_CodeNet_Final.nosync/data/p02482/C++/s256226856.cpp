#include <cmath>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <sstream>
#include <vector>

#define P(a) ((a)*(a))

using namespace std;

int main(){
    int a,b;
    cin >> a >> b;
    if(a==b) cout << "a == b";
    else if(a>b) cout << "a > b";
    else if(a<b) cout << "a < b";
    cout << endl;
    return 0;
}