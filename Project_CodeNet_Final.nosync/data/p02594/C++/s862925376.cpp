#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;

void airconditioner(signed int x){
    if(x<30){
        cout << "No";
        return;
    }
    cout << "Yes";
    return;
}

int main(){
    //ifstream myfile;
    //myfile.open("sample.txt");
    signed int x;
    cin >> x;
    airconditioner(x);
    return 0;
}