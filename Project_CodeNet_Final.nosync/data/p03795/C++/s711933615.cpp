#include<iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    int x, y;

    x= 800*N;
    y= 200*( (int) N/15 );

    cout << x-y << endl;

    return 0;
}