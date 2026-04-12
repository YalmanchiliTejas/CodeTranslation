#include <bits/stdc++.h>

using namespace std;

int main(){

    int n1, n2, n3, num;

    cin >> n1 >> n2 >> n3;

    n1 *= 100;
    n2 *= 10;
    num =  n1 + n2 + n3;

    if(num % 4 == 0){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }

    return 0;
}


