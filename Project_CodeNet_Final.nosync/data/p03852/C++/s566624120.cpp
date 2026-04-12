#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
int main(){
    string s;
    cin >> s;
    char unit[]={'a','e','i','o','u'};
    bool flag = false;
    rep(i,5){
        if(s.find(unit[i]) != -1){
            flag = true;
        }
    }
    if(flag){
        cout << "vowel" << endl;
    }else{
        cout << "consonant" << endl;
    }
}