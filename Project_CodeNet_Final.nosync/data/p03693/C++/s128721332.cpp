#include <iostream>
#include <cstdio>
#include <string>
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
using namespace std;
int main(){
    int r,g,b;
    cin >> r >> g >> b;
    if((2*g+b)%4==0){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    
    return 0;
}