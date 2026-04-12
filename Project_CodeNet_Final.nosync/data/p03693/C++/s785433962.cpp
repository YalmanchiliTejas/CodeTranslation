#include <iostream>
using namespace std;

int main(){
    int a,b,c; string s;
    cin >> a >> b >> c;
    if( (10*b+c) % 4 == 0) s = "YES";
    else s = "NO";
    cout << s << endl;
    return 0;
}