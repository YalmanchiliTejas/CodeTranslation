#include <iostream>
#include <cmath>
using namespace std;

using lli = long long int;

int main(void){
    lli k,a,b;
    cin >> k >> a >> b;
    
    if(a <= b){
        
        if(k <= a){
            cout << 1 << endl;
        }else
            cout << -1 << endl;
    }else{
        if(k <= a){
            cout << 1 << endl;
        }else{
            
            lli res = ( k + a - b - 1) / (a - b);
            
            cerr << res << endl;
            
            while(true){
                if( k > res*a - (res-1)*b ){
                    cerr << res << endl;
                    cout << 2*res+1 << endl;
                    return 0;
                }
                res--;
            }
        }
    }
    
}
