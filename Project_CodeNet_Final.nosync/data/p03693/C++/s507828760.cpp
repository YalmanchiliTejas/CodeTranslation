#include <bits/stdc++.h>
using namespace std;

int main(){
    int A, B, C;
    cin >> A >> B >> C;

    int D = A * 100 + B * 10 + C;

    if(D % 4 == 0){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}