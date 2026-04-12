#include <bits/stdc++.h>
using namespace std;

int main(){ 
    string S;
    cin >> S;
    int a = 0;
    int b = 0;
    
    for(int i = 0; i < int(S.size()); i++){
        if(S.at(i) == 'A'){
            a = 1;
        }else{
            b = 1;
        }
    }
    
    if(a == 1 and b == 1){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
   
}
        
