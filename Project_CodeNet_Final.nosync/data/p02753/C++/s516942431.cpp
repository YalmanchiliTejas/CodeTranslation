#include<bits/stdc++.h>
using namespace std;


int main(){
    string S;
    cin >> S;
    if(S.find("AB")!=-1 || S.find("BA")!=-1){
        cout << "Yes" << endl;

    }
    else{
        cout << "No" << endl;
    }


}