#include<bits/stdc++.h>
using namespace std;
using LL = long long;




int main(){
    int N;cin >> N;
    string s;cin >> s;
    int K;cin >> K;
    for(int a = 0;a < N;a++){
        if(s.at(K-1) == s.at(a)){
            cout<<s.at(a);
        }else{
            cout<<"*";
        }
    }
    cout<<endl;
}
