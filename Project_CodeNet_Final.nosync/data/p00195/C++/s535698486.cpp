#include "bits/stdc++.h"
#define rep(i,a,n) for(int (i) = (a);(i) < (n);(i)++)
using namespace std;

int main(){
    
    int n,m,memo = 0,memo_c = 0;
    
    while(1){
        cin >> n >> m;
        if(n == 0 && m == 0){
            break;
        }
        else{
            memo = n+m;
            memo_c = 0;
            
            rep(i,1,5){
                cin >> n >> m;
                if(memo < n+m){
                    memo = n+m;
                    memo_c = i;
                }
            }
            
            cout << (char)(memo_c+65) << " " << memo << endl;
            
        }
    }
    return 0;
}
