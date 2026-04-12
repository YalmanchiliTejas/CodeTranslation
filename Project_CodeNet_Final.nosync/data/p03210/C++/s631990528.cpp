#include<algorithm>
#include<iostream>
#include<map>
#include<vector>
using namespace std;
int main(){
    int X;cin >> X;
    switch(X){
        case 7:
        case 5:
        case 3:
            cout << "YES" << endl;
            break;
        default:
            cout << "NO" << endl;
            break;
    }
}