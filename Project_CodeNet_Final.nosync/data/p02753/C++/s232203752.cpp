#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main(void){
    // Your code here!
    char A,B,C;
    cin >> A >> B >> C;
    if(1 ==((A == B) + (C == A) + (B == C) )){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}
