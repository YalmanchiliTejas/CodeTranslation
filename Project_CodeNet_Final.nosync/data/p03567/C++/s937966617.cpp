#include <bits/stdc++.h>
using namespace std;
 
int main(){
    string S;
    cin >> S;

    int count = 0;
    int N = S.length();
    for (int i = 0; i < N; i++){
        if (S.substr(i, 2) == "AC"){
            count++;
        }        
    }

    if (count > 0){
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}