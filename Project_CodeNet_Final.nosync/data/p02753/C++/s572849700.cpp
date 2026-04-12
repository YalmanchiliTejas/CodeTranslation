#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;

int main(){
    string sta;
    cin >> sta;

    if(sta!="AAA" && sta!="BBB"){
        cout << "Yes" << endl;
    }
    else{cout << "No" << endl;}

    return 0;
}