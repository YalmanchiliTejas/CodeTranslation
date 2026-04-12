#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int a,f;
    f=0;
    for(a=0;a<2;a++){
        if(s.at(a)!=s.at(a+1)){
            f++;
        }
    }
    if(f==0){
        cout << "No" << endl;
    }
    else{
        cout << "Yes" << endl;
    }

    return 0;
}