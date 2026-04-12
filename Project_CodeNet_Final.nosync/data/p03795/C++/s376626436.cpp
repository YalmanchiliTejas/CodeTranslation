#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    int x=0,y=0;
    for (int i=0; i<N; i++){
        x += 800;
        if((i+1)%15==0) y += 200;
    }
    cout << x-y;

}