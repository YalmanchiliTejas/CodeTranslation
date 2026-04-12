#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(s);i<(int)(n);i++)
typedef long long ll;
const int INF=1e+09;



int main(){    
    //入力
    string S;

    cin >> S;
    if(S[0]==S[1]&&S[1]==S[2]){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
}