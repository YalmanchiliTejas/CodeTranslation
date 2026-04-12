#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int y = 200*(n/15);

    int x = 800*n;

    cout << (x -y) << endl;
}