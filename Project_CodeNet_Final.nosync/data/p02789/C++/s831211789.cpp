#include <iostream>
using namespace std;

int main(){
    int x,y;
    while(cin >> x >> y){
        if(x==y){
            cout << "Yes" << '\n';
        }else{
            cout << "No" << '\n';
        }
    }  
}