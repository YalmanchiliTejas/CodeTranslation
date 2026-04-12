#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main(){
    char s[5];
    cin >> s;
    bool f=0;
    for(int i=0;i<5;i++){
        if(s[i]=='A' && s[i+1]=='C'){
            f=1;
        }
    }
    cout << (f==1?"Yes":"No") << endl;
}