#include <iostream>
#include <string>
using namespace std;
int main(){
    int a;
    cin >> a;
    if((1<a && 9>a) && a%2==1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}