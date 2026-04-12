#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
using namespace std;
typedef long long ll;

int main(){
    
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int a_price, b_price, ab_price, a_needed, b_needed;
    cin >> a_price >> b_price >> ab_price >> a_needed >> b_needed;
    
    if((a_price+b_price+1)/2<=ab_price){
        cout << a_price * a_needed + b_price * b_needed << endl;
    } else {
        
        ll gathered_value;
        
        if(a_needed>b_needed){
            gathered_value = ab_price * min(a_needed,b_needed) * 2 + a_price * (a_needed - b_needed);
        } else if(a_needed<b_needed){
            gathered_value = ab_price * min(a_needed,b_needed) * 2 + b_price * (b_needed - a_needed);
        } else {
            cout << ab_price * min(a_needed,b_needed) * 2 << endl;
            return 0;
        }
        
        int c = min(a_needed,b_needed);
        int d = max(a_needed,b_needed);
        
        if(a_needed > b_needed){
            for(int i = c + 1; i <= d; i++){
                ll added_value = ab_price*i*2 + a_price*(d-i);
                gathered_value = min(added_value,gathered_value);
                
            }
        } else if(b_needed > a_needed){
            for(int i = c + 1; i <= d; i++){
                ll added_value = ab_price*i*2 + b_price*(d-i);
                gathered_value = min(added_value,gathered_value);
                
            }
        }
        cout << gathered_value << endl;
    }
}


