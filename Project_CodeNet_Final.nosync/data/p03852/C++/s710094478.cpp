#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string a;
    bool flag=false;
    cin>>a;
    if(a=="a"||a=="e"||a=="i"||a=="o"||a=="u"){
        flag=true;
    }
     flag ? cout<<"vowel"<<endl : cout<<"consonant"<<endl;

    return 0;
}