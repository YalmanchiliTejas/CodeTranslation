#include<bits/stdc++.h>
using namespace std;

int main(){
    string stations;
    cin >> stations;
    int countA = 0;
    for(int i = 0; i < 3; i++){
        if( stations.at(i) == 'A'){
            countA++;
        }
    }
    if(countA == 3 || countA == 0){
        cout << "No" << endl;
    }else cout << "Yes" << endl;
}