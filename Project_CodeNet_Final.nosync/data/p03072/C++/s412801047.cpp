#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define FOR(i,a,b) for(int i =(a) ; i <= (b); i++)
#define ROF(i,a,b) for(int i =(b) ; i >= (a); i--)
#define REP(i,n)  FOR( i, 0, (n) - 1 )
#define PER(i,n)  ROF( i, 0, (n) - 1 )

int main(){
    int N,H[21],max=0,ans=0;
    cin >> N;
    REP(i,N){
        cin >> H[i];
        if(max <= H[i]){
            ans++;
            max = H[i];
        }
    }
    cout << ans << endl;
    return 0;
}