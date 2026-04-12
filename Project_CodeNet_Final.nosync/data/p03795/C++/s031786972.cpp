#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    int N;

    cin >> N;
    int x = 800*N;
    int y = N / 15 * 200;

    cout << x - y << endl;

    return 0;
}