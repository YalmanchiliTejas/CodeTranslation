#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    cin >> a;
    if(a<15){
        cout << a*800 << endl;
    }
    else{
        b=a/15;
        cout << a*800-b*200 << endl;
    }
    return 0;
}