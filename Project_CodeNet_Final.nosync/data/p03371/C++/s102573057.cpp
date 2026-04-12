#include <bits/stdc++.h>
using namespace std;
int main(){
    int A,B,C,X,Y;
    cin>>A>>B>>C>>X>>Y;
    long long AB=A*X+B*Y;
    int ans=0;
    for(int i=0;i<100001;i++){
        ans = i*2*C+max(0,X-i)*A+max(Y-i,0)*B;
        if(ans<AB)AB=ans;
    }
    cout<<AB<<endl;
}