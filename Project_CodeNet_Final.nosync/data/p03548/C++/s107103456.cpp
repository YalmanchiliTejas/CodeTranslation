#include<bits/stdc++.h>
using namespace std;

int main(void){
    int x, y, z;
    cin >> x >> y >> z;

    int cnt = 0;
    int residue = x;

    //first 

    residue = residue -2 * z - y;
    cnt++;

    while(residue >= y + z){
        residue =  residue - z - y;
        cnt++; 
    }
    cout << cnt << endl;
    return 0;
}