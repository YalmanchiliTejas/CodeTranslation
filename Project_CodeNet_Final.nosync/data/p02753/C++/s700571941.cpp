#include<iostream>
#include<algorithm>
#include<stack>
#include<string>

using namespace std;
int a[200];
int main(){
    string s;
    int a, b;
    a=b=0;
    cin >> s;
    for(int i=0;i<3;i++){
        if(s[i]=='A') a=1;
        if(s[i]=='B') b=1;
    }
    if(a==1&&b==1) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}