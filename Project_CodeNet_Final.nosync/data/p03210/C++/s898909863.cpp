#include <bits/stdc++.h>
using namespace std;
void YesNo(bool);
void YESNO(bool);


int main(){
    int a;
    cin >> a ;
    YESNO(a == 7|| a == 5 || a == 3);
    
}


void YesNo(bool x){
    if (x) {
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    
}

void YESNO(bool x){
    if (x) {
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    
}
