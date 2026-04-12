#include <iostream>
#include <string>

using namespace std;

int main(void){
    string r,g,b;
    string num;
    int a=0;

    cin >> r >> g >> b;

    num=r+g+b;

    a=stoi(num);

    if(a%4==0)cout << "YES" << endl;
    else cout << "NO" << endl;
    
    return 0;
}