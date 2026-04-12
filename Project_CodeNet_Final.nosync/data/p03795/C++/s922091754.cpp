#include<iostream>
using namespace std;
int main() {
    int N;
    cin >> N;
    int x,y,Y=0;
    for(int i=1; i <= N/15; i++){
        Y = Y+1;
    }
    x = 800*N;
    y = 200*Y;
    cout << x-y << endl;
}