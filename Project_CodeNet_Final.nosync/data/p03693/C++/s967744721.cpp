#include <iostream>
using namespace std;

int main(void){
    char a, b, c;
    int n;
    cin >> a >> b >> c;
    string s="";
    s += a;
    s += b;
    s += c;
    n = stoi(s);
    if(n%4 == 0){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}