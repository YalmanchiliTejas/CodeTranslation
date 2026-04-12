#include <bits/stdc++.h>
using namespace std;
#define LL long int
#define MOD (LL)pow(10,9) + 7


int main(){
    string a;
    cin >> a;
    bool fa = false,fb = false;

    for(int i = 0;i < 3; ++i){
        if(a[i] == 'B'){
            fb = true;
        }else{
            fa = true;
        }
    }

    if(fa && fb){
        cout << "Yes" << endl;
    }else {
        cout << "No" << endl;
    }
}

