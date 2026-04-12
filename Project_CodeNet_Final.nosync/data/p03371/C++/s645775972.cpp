#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i, n) for(int i =0; i < n ;i++)
using namespace std;

int main(){
    
    int A, B , C, X, Y;
    cin >>A >>  B >> C >> X >> Y;
    long long ans = A * X + B *Y;

    int N1  = min(X, Y);
    int N2  = max(X, Y);

    rep(i, N1){
        ans = min(ans, ans + 2 * C- A -B);
    }
    int z;
    if(X > Y) z=A;
    else z=B;
    rep(i, N2 - N1){

        ans = min(ans, ans + 2 * C- z); 
    } 

    cout << ans << endl;


    return 0;
}