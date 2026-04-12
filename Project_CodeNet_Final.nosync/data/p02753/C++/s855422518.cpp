#include<iostream>
#include<string>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    string s;
    cin >> s;
    int a[2] = {0, 0};
    rep(i, 3){
        if(s[i] == 'A'){
            a[0]++;
        }else if(s[i] == 'B'){
            a[1]++;
        }
    }
    if(a[0] != 0 && a[1] != 0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}