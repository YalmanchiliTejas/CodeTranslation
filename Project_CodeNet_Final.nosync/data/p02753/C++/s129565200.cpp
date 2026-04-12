#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int A = 0;
    int B = 0;
    string s;
    cin >> s;

    for(int i=0;i<3;++i){
        if(s[i] == 'A'){
            A++;
        }else{
            B++;
        }
    }

    if((A == 0) || (B == 0)){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
    return 0;  
}