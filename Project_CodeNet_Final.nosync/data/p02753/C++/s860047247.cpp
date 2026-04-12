#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main(){
    string s;
    cin >> s;
    int flag = 0;
    if(s == "AAA" || s == "BBB"){
        flag = 1;
    }

    if(flag == 0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}