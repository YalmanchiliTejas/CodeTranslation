#include <bits/stdc++.h>
using namespace std;
int main(void){
 
    int A,B,C,X,Y;
    
    cin >> A >> B >> C >> X >> Y;
    
    int ans = 0;


    if( A + B <= 2*C){ //ABピザで買うと得しない場合。
        
        ans = A * X + B * Y;
        
    }else{ //ABピザで買うと得する場合
    
        if( X > Y ){ //Aピザの方がたくさん必要。
            
            if( A > 2*C){
                
                ans = C * 2 * Y + C * 2 * (X - Y);
                
            }else{
               
                ans = C * 2 * Y + A  * (X - Y);
                
            }
            
        }else{
    
            if( B  > 2*C){
                
                ans = C * 2 * X + C * 2 * (Y - X);
                
            }else{
               
                ans = C * 2 * X + B  * (Y - X);
                
            }
    
        }
    }
   
   cout << ans << endl;
    
}