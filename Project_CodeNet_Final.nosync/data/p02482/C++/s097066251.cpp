#include<iostream>
using namespace std;

int main(){
    int x,y;
    cin >> x >> y;
    
    if (x == y){
        cout << "a == b";
    } else if(x < y){
        cout << "a < b";
    } else if(x > y){
        cout << "a > b";
    }
    cout << endl;     
    
    return 0;
}