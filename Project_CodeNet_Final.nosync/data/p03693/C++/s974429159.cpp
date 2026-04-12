#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cctype>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    int r, g, b;
    cin >> r >> g >> b;
    int tmp=g*10+b;
    if(tmp%4==0){
        cout << "YES";
    }else{
        cout << "NO";
    }
    
    return 0;
}