#include<bits/stdc++.h>
using namespace std;
using ll=long long;



int main(){
    int A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;
    ll ans1=A*X+B*Y;
    ll ans2=C*max(X,Y)*2;
    ll ans3=C*min(X,Y)*2;
    if(min(X,Y)==X){
        ans3+=B*(Y-X);
    }
    else{
        ans3+=A*(X-Y);
    }
    ll ans4=min(ans1,ans2);
    cout << min(ans3,ans4) << endl;
}