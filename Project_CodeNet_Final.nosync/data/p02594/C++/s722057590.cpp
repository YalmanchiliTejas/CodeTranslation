#include <bits/stdc++.h>
using namespace std;

const string YES = "Yes";
const string NO = "No";
using ll = long long;

void solve(long long X){
    if(X >= 30){
        cout<<YES<<endl;
    }else{
        cout<<NO<<endl;
    }
}

int main(){
    long long X;
    scanf("%lld",&X);
    solve(X);
    return 0;
}
