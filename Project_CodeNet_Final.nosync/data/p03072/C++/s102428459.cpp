#include <iostream>
using namespace std;
int main(void){
    int N;
    int ans=1;
    int h[20];
    cin >> N;
    for (int i=0;i<N;i++){
        cin >> h[i];
    }
    
    int highest = h[0];
    
    if ( h[1] > h[0] ){
            ans++;
            highest = h[1];
        }else if ( h[0] == h[1] ){
            ans++;
        }
        
        
    for (int i=2;i<N;i++){
        if ( h[i] > highest ){
            ans++;
            highest = h[i];
        }else if ( h[i] == highest ){
            ans++;
        }
    }
    
    cout << ans << endl;
    
}