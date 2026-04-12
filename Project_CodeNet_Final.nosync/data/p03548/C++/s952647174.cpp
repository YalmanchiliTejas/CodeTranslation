#include<iostream>

using namespace std;

int main(){
    int x, y , z;
    cin >> x >> y >> z;
    for(int i=0;i<1000000;i++){
        if(x<i*y+(i+1)*z){
            cout << i-1 << endl;
            break;
        }
    }
}