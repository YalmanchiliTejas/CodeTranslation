#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define SORT(a) sort(a.begin(),a.end())
using namespace std;
int main(){
    //Seiranchan!
    int X,Y,Z,ans;;
    cin >>X>>Y>>Z;

    for (int i=0;i*Y+(i+1)*Z<=X;i++){
        ans = i;
    } 
    cout << ans <<endl;
}
