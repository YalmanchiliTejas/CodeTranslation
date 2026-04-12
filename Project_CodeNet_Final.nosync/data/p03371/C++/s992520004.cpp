#include<iostream>
#include<iomanip>
#include<algorithm>

using namespace std;

#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)

int main(){
    int Atmp,Btmp,AB,Xtmp,Ytmp;
    cin >> Atmp >> Btmp >> AB >> Xtmp >> Ytmp;
    int ans;
    int A,B,X,Y;
    X = min(Xtmp,Ytmp);
    Y = max(Xtmp,Ytmp);
    if(X==Xtmp){
        A = Atmp;
        B = Btmp;
    }else{
        A = Btmp;
        B = Atmp;
    }
    if(A+B>2*AB){
        ans = min(AB*2*X+B*(Y-X),AB*2*Y);
    }else{
        ans = A*X + B*Y;
    }
    cout << ans;
}