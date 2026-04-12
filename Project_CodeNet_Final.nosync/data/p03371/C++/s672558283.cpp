#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<set>
using namespace std;

int main(void){
    int A, B, C, X, Y;
    cin>>A>>B>>C>>X>>Y;
    int ans=A*X+B*Y;
    for(int k=1;k<=max(X,Y);k++){
        ans=min(ans,2*C*k+max(0,X-k)*A+max(0,Y-k)*B);
    }
    cout<<ans;
}