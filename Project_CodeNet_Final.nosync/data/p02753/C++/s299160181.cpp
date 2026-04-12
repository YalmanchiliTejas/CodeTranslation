#include<iostream>
using namespace std;

int main(void){
    string S;
    cin >> S;
    int A{0}, B{0};
    for(int i{0}; i<3; ++i){
        if(S[i]=='A'){
            ++A;
        }
        else{
            ++B;
        }
    }
    if(A>=1 and B>=1){
        cout << "Yes" <<endl;
    }
    else{
        cout << "No" <<endl;
    }

}
