#include <iostream>
using namespace std;
int main(void){
    // Here your code !
    
    int N;
    int Total = 0;
    cin >> N;
    
    for( int i = 1; i <= N; i++ ){
        
        Total = Total + 800;
        
        if( i%15 == 0 ){
            Total = Total - 200;
        }
    }
    
    cout << Total;
    
    return 0;
}
