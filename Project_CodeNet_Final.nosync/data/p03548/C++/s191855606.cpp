#include<iostream>
using namespace std;

int main(){
    int x, y, z;
    cin >> x >> y >> z;

    int cnt = 0;
    int size = 0;
    while(true){
        size += (y + z);
        if(size < x && (x - size) >= z){
            cnt++;
        }
        else{
            break;
        }
    }

    cout << cnt << endl;

    return 0;
}