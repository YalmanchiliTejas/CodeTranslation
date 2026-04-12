#include <stdio.h>
#include <string>
#include <iostream>
#include <iomanip>
#include <map>
#include <algorithm>
#include <vector>
#include <math.h>
#define INF 1000000007
using namespace std;

int main(void){
    int n;
    cin >> n;
    if(n==3 || n==5 || n==7){
        cout << "YES" << endl;
        return 0;
    }else {
        cout << "NO" << endl;
    }
    return 0;
}
