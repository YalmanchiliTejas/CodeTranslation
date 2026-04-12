#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<set>
#include<map>
using namespace std;


int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int res = 100*a + 10*b + c;
    if(res%4 == 0){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}
