#include <iostream>
using namespace std;
int main(void){
    int A, B, C, X, Y;
  int ans[2];
    cin >> A>> B>> C>> X>> Y;
  
    int tmp = 0;
    if (X > Y){
        ans[0] = (X - Y)*A;
        ans[1] = (X *2)*C;
        X = X - (X - Y);
    } else if (Y > X) {
        ans[0] = (Y - X)*B;
        ans[1] = (Y *2)*C;
        Y = Y - (Y - X);
    } else {
        ans[1] = (Y *2)*C;
    }
    if(X!=0 && Y!=0) {
        int CM = C * (X * 2);
        int ABM = (A + B) * X ;
        if (CM > ABM) ans[0] += ABM;
        else ans[0] += CM;
    }
    
    if (ans[0] > ans[1])
        cout << ans[1]<< endl;
    else 
        cout << ans[0] << endl;
    
    
}