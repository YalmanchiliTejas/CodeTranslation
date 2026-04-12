#include <bits/stdc++.h>
#include <string>
using namespace std;

int main(){
    string N;
    cin >> N;
    int A=0;
    for(int i=0;i<3;i++){
        if(N[i] == 'A') A++;
    }
    if(A==0 || A==3) cout<<"No";
    else cout <<"Yes";
}