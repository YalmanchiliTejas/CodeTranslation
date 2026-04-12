#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define int long long  
signed main(){
    int H,W;
    char A;
    int Sum=0;
    cin >> H >> W;
    REP(i,H){
        REP(j,W){
            cin >> A;
            if(A=='#'){
                Sum++;
            }
        }
    }
    if(Sum==H+W-1){
        cout << "Possible" << endl;
    }else{
        cout << "Impossible" << endl;
    }
    
	return 0;
}
