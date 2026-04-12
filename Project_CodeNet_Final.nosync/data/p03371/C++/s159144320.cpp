#include <bits/stdc++.h>
using namespace std;
int A,B,C,X,Y;
int solve(int x,int y){
    long long int ans = 0;
    while(x<X || y<Y){
        if(A+B >= 2*C && (x<X) && y<Y){
            x++;
            y++;
            ans += 2*C;
        }
        else if(X<=x && y<Y){
            if(2*C<=B){
                ans += 2*C;
                x++;
                y++;
            }
            else {
                ans += B;
                y++;
            }
        }
        else if(Y<=y && x<X){
            if(2*C<=A){
                ans += 2*C;
                x++;
                y++;
            }
            else {
                ans += A;
                x++;
            }
        }
        else{
            ans += A*(X-x) + B*(Y-y);
            x = X;
            y = Y;
        }
    }
    return ans;
}


int main(){
    cin>>A>>B>>C>>X>>Y;
    long long int ans = solve(0,0);
    cout<<ans<<endl;
    return 0;
}