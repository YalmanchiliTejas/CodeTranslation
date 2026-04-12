#include<bits/stdc++.h>
using namespace std;

int main() {
    char tmp;
    string a;
    cin >> a;
    tmp = a[0];
    bool flag=false;
    for (int i=1;i<3;i++){
        if (a[i]!=tmp) flag=true;
    }
    if (flag){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}