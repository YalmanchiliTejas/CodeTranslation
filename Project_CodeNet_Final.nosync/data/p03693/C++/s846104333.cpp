#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
int main(){
    int n0, n1, n2, ans;
    cin >> n0 >> n1 >> n2;
    ans = n0*100 + n1*10 + n2;
    if(ans%4 == 0){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}