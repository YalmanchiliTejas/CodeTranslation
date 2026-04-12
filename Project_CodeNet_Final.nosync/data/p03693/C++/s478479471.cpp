#include<iostream>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
typedef long long ll;

int main(){
    int r, g, b;
    cin >> r >> g >> b;
    int ans = r*100 + g*10 + b;
    if(ans%4==0){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}