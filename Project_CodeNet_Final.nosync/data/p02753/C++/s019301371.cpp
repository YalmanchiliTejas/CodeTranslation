#include <bits/stdc++.h>
using namespace std;

int main() {
    vector <char> S(3);

    cin>>S.at(0)>>S.at(1)>>S.at(2);

    if(S.at(0)==S.at(1)&&S.at(0)==S.at(2)){
        cout << "No" <<endl;
    }else{

        cout << "Yes" << endl;
    }
    
}