#include <iostream>
using namespace std;

int main(){
    string S;
    cin >> S;

    if (S[0] != S[1] || S[1] != S[2])
    {
        cout << "Yes"; 
    }else{
        cout << "No";
    }
    return 0;
}