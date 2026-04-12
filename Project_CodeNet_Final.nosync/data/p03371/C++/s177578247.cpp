#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define pb push_back
#define ALL(obj) (obj).begin(), (obj).end()

using namespace std;
int A,B,C,X,Y;
int main(){
    cin >> A >> B >> C >> X >> Y;
    int num;
    if(X >= Y) num = Y*2*C + (X-Y)*A;
    else num =  X*2*C + (Y-X)*B;
    
    cout << min(C*2*max(X,Y),min(num ,A*X + B*Y)) << endl;
}