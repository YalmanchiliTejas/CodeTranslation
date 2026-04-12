#include <bits/stdc++.h>
using namespace std;
#define int long long
using vec_int = vector<int>;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int charToInt(char c){
    char zero_num = '0';
    return (int)c - (int)zero_num;
}

signed main(){
    int A, B, C, X,Y; cin>>A>>B>>C>>X>>Y;

    int min_XY = X>Y? Y : X;
    int max_XY = X>Y? X : Y;
    int max_price = X>Y? A : B;

    if(A+B<=2*C){
        cout<<X*A + Y*B<<endl;
        return 0;
    }else{
        if(max_price>2*C){
            cout<<max_XY*C*2<<endl;
        }else{
            cout<<min_XY*C*2+ max_price*(max_XY-min_XY)<<endl;
        }
    }

    return 0;
}