#include<iostream>

using namespace std;

int main(){
    int x;
    
    cin >> x;
    if(x > 40 || x < -40){
        return 0;
    }
    if(x < 30){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
}