#include<iostream>
#include<string>
#include <algorithm>
using namespace std;
int main()
{
    int r, g, b;
    cin >> r >> g >> b;

    int v = 0;
    v += r*100;
    v += g*10;
    v += b;

    if(v%4 == 0){
      cout << "YES";
    }else{
      cout << "NO";
    }
    cout << endl;

    return 0;
}
