#include <iostream>
#include <string>
using namespace std;

int main(){
    int r,g,b;
    cin >> r >> g >> b;
    int N = r*100 + g*10 + b;
    if(N % 4 == 0){
        cout << "YES";
    }else{
        cout << "NO";
    }
    return 0;
}