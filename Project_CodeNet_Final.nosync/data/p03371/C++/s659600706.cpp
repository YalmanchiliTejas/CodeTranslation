#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<n;i++)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    int A,B,C,X,Y;
    int ans;
    cin >>A>>B>>C>>X>>Y;
    int mx =max(X,Y);
    if(A+B>2*C){
        if(X>=Y){
            ans = min(2*C*mx,2*C*Y + A*(X-Y));
        }
        else ans = min(2*mx*C,2*C*X + B*(Y-X));
    }
    else ans = A*X + B*Y;



    cout << ans <<endl;
}