#include <bits/stdc++.h>
using namespace std;

int main(void){
 
    int data[3];
    int v;
    for(int i=0;i<3;i++){
        cin >> data[i];
    }
    
    v = data[0] * 100 + data[1] * 10 + data[2];
    
    if(v % 4 == 0){
        cout << "YES" <<endl;
    }
    else{
        cout << "NO" <<endl;
    }
    
}