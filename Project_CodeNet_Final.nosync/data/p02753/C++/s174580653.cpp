#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main(){
    string n;
    cin >> n;

    char s1 = n[0];
    char s2 = n[1];
    char s3 = n[2];

    if(s1 == s2 && s2 == s3){
        cout << "No" << endl;
    }
    else{
        cout << "Yes" << endl;
    }

    
}