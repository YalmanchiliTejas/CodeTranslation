#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

long long ans = 0;

int comb(int n ,int k){
    if(k == 3){
        return n*(n-1)*(n-2)/6;
    }
    else if(k == 2){
        return n*(n-1)/2;
    }
    else if(k == 1) return n;
    else return 1;
}

void solve(string s, int k){
    int n= s.size();
    if(n < k) return;
    if(k == 0){
        ans += 1;
        return;
    }
    int a = s.at(0) - '0';
    string sub = s.substr(1, string::npos);
    if(a > 0){
    ans += comb(n-1,k)*pow(9,k);
    ans += (a-1)*comb(n-1,k-1)*pow(9,k-1);
    solve(sub,k-1);
    }
    else{
        solve(sub,k);
    }
}

int main(){
    string s;
    cin >> s;
    int k;
    cin >> k;
    solve(s,k);
    cout << ans << endl;
}


