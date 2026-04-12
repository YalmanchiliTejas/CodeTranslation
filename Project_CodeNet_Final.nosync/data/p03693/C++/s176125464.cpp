#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


int main(int argc, const char * argv[]) {
    int a,b,c;
    cin >> a >> b >> c;
    if((a*100+b*10+c)%4){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }
    return 0;
}
