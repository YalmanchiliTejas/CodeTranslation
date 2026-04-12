#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define REP(i,n)    for(int i = 0; i < (int)n; i++)
#define MAX_N   100000
#define MAX_M   100000


void solve(){
    char S[3];
    cin >> S;
    if(S[0]==S[1]&&S[1]==S[2])
        cout << "No\n";
    else
        cout << "Yes\n";
    
}

int main(){
    solve();
    return 0;
}