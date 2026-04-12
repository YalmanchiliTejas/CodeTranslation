#include <iostream>
#include <cmath>
#include <string>
#include <typeinfo>
#include <climits>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <stdio.h>
#include <cstdlib>
using namespace std;

int main(){
    int a,b,c;
    cin >> a >> b >>c;
    if((100*a+10*b+c)%4==0){
        cout << "YES";
    }else{
        cout << "NO";
    }
}
