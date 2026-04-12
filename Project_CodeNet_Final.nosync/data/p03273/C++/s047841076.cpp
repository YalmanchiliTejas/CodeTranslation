#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
    int H,W; cin >> H >> W;

    vector<string> A;
    for(int i=0; i<H; i++){                     //.だけのstringは弾く
        string s; cin >> s;
        bool flg=true;
        for(int j=0; j<W; j++){
            if(s[j]!='.') flg=false;
        }
        if(!flg) A.push_back(s);
    }

    vector<string> B(A.size());

    for(int i=0; i<W; i++){              //縦の部分を弾く　
        bool flg=true;
        for(int j=0; j<A.size(); j++){
            if(A[j][i]!='.') flg=false;
        }

        if(!flg){
            for(int j=0; j<A.size(); j++){
                B[j]+=A[j][i];
            }
        }
    }

    for(int i=0; i<B.size(); i++) cout << B[i] << endl;

}