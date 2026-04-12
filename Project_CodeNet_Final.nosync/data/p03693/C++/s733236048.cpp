#include <iostream>
using namespace std;

int main(void){
    // Your code here!
    int r,g,b;
    cin >> r >> g >> b;
    if((r *100 +  g * 10 +  b)%4){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }
    
}
