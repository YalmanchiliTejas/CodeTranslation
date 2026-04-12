#include <bits/stdc++.h>
using namespace std;






//A
int main(){
    char test[3];
    for(int i = 0;i < 3;i++){
        cin >> test[i];
    }
    if(test[0] == test[1] && test[1] == test[2]){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
}




