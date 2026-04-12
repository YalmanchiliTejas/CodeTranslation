#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const string YES = "YES";
const string NO = "NO";

void solve(long long X){
    if(X ==3||X==5||X==7){
        cout << YES << endl;
    }else{
        cout << NO <<endl;
    }

}

int main(){
    long long X;
    scanf("%lld",&X);
    solve(X);
    return 0;
}
