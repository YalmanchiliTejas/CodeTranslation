#include <bits/stdc++.h>
using namespace std;

int main(){
    int d;
    cin >> d;
    string frag = "NO";
    if(d == 3 or d == 5 or d == 7){
        frag = "YES";
    }
    cout << frag << endl;
}