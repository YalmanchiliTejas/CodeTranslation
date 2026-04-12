#include<iostream>
#include<vector>
#include<queue>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    int x, y, z;
    string s, t;

    cin >> x >> y >> z ;
    
    int count=0;
    for(int i=1;i<x;i++){
        if (i*(y+z) + z <= x)count++;
        if (i*(y+z) + z > x)break;
    }


    cout <<  count;

    return 0;
}




