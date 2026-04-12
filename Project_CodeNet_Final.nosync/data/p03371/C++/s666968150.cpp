#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int A,B,C,X,Y;
    cin>>A>>B>>C>>X>>Y;
    long long COA;
    long long COB;
    long long  COC;
    COA=A*X+B*Y;
    int MIN=min(X,Y);
    COB=MIN*C*2+A*(X-MIN)+B*(Y-MIN);
    int MAX=max(X,Y);
    COC=MAX*C*2;
    long long ans=min(COA,min(COB,COC));
    cout <<ans<<endl;
}