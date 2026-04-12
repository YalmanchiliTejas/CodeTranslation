#include <bits/stdc++.h>
using namespace std;
int main(){
    string x;
    cin >> x;
    int a = 0, b = 0;
    for(int i = 0;i < 3;i++){
        if(x[i] == 'A'){
            a++;
        }
        else{
            b++;
        }
    }
    if(a && b){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }
}
