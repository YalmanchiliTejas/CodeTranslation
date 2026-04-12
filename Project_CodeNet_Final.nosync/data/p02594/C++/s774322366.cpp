#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <numeric>
#include <queue>
using namespace std;

int64_t min(int64_t a,int64_t b) {
    if (a > b)
    {
        return b ;
    }else
    {
        return a ;
    }
}

int main(){    
    int n ;
    cin >> n ;
    if (n >= 30)
    {
        cout << "Yes" << endl ;
    }else
    {
        cout << "No" << endl ;
    }
    
    
}
