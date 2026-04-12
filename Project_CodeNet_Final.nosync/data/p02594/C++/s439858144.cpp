#include<iostream>
using namespace std;

int X;

void read() {
    cin >> X;
}


void work() {
    cout << (X >= 30 ? "Yes" : "No") << endl;
}


int main() {
    read();
    work();
    return 0;
}
