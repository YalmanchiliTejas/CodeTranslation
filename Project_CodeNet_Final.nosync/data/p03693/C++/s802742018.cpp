#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#define endl "\n"
using namespace std;

int main()
{
    int r, g, b;
    cin >> r >> g >> b;

    int val = r * 100 + g * 10 + b;
    if(val % 4 == 0)
    	cout << "YES" << endl;
    else
    	cout << "NO" << endl; 
}