#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <new>

using namespace std;

typedef long long ll;

#define rep(i, N) for (ll i = 0; i < (ll)(N); ++i)

int main(){
    ll Aflag = 0,Bflag=0;
    string S;
    cin >> S;
    for(ll i =0;i<3;i++){
        if(S[i]=='A'){
            Aflag = 1;
        }
        if(S[i]=='B'){
            Bflag = 1;
        }
    }
    if(Aflag==1&&Bflag==1){
        cout << "Yes" <<endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}