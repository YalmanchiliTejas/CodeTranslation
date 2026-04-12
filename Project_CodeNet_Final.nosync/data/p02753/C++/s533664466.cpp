#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(){
    string a;
    cin >> a;
    if (a[0] == a[1] && a[1] == a[2]){
        cout << "No" << endl;
    }
    else{
        cout << "Yes" << endl;
    }
}