#include<iostream>
#include<iomanip>
#include<algorithm>

using namespace std;

#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)

int main(){
    int X,Y,Z;
    cin >> X >> Y >> Z;
    cout << (X-Z)/(Y+Z);
}