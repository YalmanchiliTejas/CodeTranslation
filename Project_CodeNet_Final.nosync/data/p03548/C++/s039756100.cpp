#include <iostream>
using namespace std;
int main(void){
    int a,b,c;
    cin >> a >> b >> c;
    if( a / (b+c) * (b+c) + c <= a){
        cout << a/(b+c) << endl;
    }else{
        cout << a/(b+c) - 1 << endl;
    }
}
