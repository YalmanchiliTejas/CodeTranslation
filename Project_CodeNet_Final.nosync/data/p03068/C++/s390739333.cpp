#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,K;
    string Str;
    cin >> N >> Str >> K;
    K--;
    for(int i=0; i<N; i++){
        if(Str.at(i)==Str.at(K)){
            cout << Str.at(K);
        }else{
            cout << '*';
        }
    }
    return 0;
}