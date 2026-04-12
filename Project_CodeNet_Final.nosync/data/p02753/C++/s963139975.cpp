#include <iostream>

using namespace std;

int main(){
    string stations;
    cin >> stations;
    bool bRet=false;

    for(int i=0;i<2;i++){
        if(stations[i]!=stations[i+1]){
            bRet = true;
            break;
        }
    }

    if(bRet){
        cout << "Yes\n";
    }else{
        cout << "No\n";
    }
}