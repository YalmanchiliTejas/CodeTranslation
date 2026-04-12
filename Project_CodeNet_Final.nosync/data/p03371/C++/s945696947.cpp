#include <bits/stdc++.h>
using namespace std;
using pint = pair<int,int>;

const long long INFLL = 1LL << 60;
const int INFI = 1000000000;


int main(){
    int A,B,C,X,Y; cin >> A >> B>> C >> X >> Y;
    int Z;
    int ans = 0;
    if(X > Y) Z = Y; else Z = X;
    if(C*2 > (A+B)) ans+= X*A+Y*B;
    else {
        if(A>C*2) A = C*2;
        if(B>C*2) B = C*2;
        ans+=Z*(C*2) + (X-Z)*A + (Y-Z)*B;
    }
    
    cout << ans << endl;
}

