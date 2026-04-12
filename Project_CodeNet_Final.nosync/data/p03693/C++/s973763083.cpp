#include <iostream>
#include <algorithm>
using namespace std;
int main (){
    int a,b,c;
    cin >> a>>b>>c;
    int d=b*10+c;
    if(d%4==0){
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;
    return 0;
}