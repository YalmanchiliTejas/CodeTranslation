#include <iostream>
#include <vector>
using namespace std;

int main(){

    int x,y,z,c=0;

    cin >> x >> y >> z;

    while( z + (y+z)*c <= x ){
       c++;
    }

    cout << c-1 << endl;
}



