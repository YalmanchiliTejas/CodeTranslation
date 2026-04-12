#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    string s;
    int A=0,B=0;
    cin>>s;
    for(int i=0; i<3; i++){
        if(s[i] =='A'){
            A++;
        }
        else{
            B++;
        }
    }
    if(A>=1&&B>=1){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}
