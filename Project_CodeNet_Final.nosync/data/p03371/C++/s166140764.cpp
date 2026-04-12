#include <bits/stdc++.h>
using namespace std;
 

int main()
{
    int A,B,C;
    int ab_price = 0;
    int sa = 0;
    int harf_price = 0;
    int harf_price2 = 0;
    vector<int> price;
    
    cin >> A >> B >> C;
    
    int X,Y;
    
    cin >> X >> Y;
    
    ab_price = A + B;
    sa = abs(X - Y);
    if(ab_price < C*2){
        cout << A * X + B * Y << endl;        
    }else{
        if(X > Y){
            harf_price = Y * C * 2;
            if(A < C*2){
                cout << harf_price + sa * A << endl;
            }else{
                cout << harf_price + sa * C * 2 << endl;
            }
        }else{
            harf_price2 = X * C * 2;
            if(B < C*2){
                cout << harf_price2 + sa * B << endl;
            }else{
                cout << harf_price2 + sa * C * 2 << endl;
            }                   
        }
    } 
    return 0;
}