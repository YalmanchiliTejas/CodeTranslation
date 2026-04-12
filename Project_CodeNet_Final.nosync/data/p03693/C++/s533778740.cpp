#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int main(){
    int r,g,b;
    cin >> r >> g >> b;
    int ans=0;
    ans=r*100+g*10+b;
    if(ans%4==0){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}
