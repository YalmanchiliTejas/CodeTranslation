#include<iostream>
using namespace std;


int N, M;

void read() {
    cin >> N >> M;
}


void work() {
    cout << (N == M ? "Yes" : "No") << endl;
}


int main() {
    read();
    work();
    return 0;
}
