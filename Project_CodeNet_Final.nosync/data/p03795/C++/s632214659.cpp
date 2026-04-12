#include<vector>
#include <iostream>

using namespace std;

int main(){
    int x = 0;
    int y = 0;
    int x1 = 0;
    cin >> x;
    for(int i = 0; i < x; i++){
        if((i+1) % 15 == 0){
            y += 200;
        }
        x1 += 800;
    }
    cout << x1 - y << endl; 
}