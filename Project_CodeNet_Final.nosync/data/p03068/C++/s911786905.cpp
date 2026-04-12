#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,K;
    cin >> N;
    string s;
    cin >> s;
    cin>>K;
    K--;
    char ans = s[K];
    for(int i = 0; i< N; i++){
        if(s[i] != ans){
            s[i] = '*';
        }
    }
    cout << s <<  endl;
    return 0;
}