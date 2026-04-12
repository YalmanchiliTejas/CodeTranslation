#include<iostream>
#include<string.h>
using namespace std;

int main(){
    int r, g, b,num;
    string s;
    cin >> r >> g >> b;
    s = to_string(r) + to_string(g) + to_string(b);
    if (atoi(s.c_str())%4==0)cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
