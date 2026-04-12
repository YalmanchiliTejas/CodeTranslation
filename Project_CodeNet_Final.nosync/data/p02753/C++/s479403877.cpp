#include <bits/stdc++.h>
using namespace std;


int main(){
    vector<char> S(3);
    bool A=false;
    bool B=false;
    for(int i=0;i<3;i++){
        cin >> S.at(i);
        if(S.at(i)=='A') A=true;
        if(S.at(i)=='B') B=true;
    }
    if(A && B){
      cout << "Yes";
    }
    else{
      cout << "No";
    }
    


}
    