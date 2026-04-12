#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<long long> len(55);
vector<long long> pat(55);

// level nバーガーに関して
// 下からx番目まで食べる時
// パティの値を返す
long long solve(long long n, long long x){
    
    if (x == len[n]) return pat[n];
    long long ans = 0;
    x--;
    
    if (x){
        long long l = min(x,len[n-1]);
        ans += solve(n-1,l);
        x -= l;
    }
    
    if (x){
        ans++;
        x--;
    }
    
    if (x){
        long long l = min(x,len[n-1]);
        ans += solve(n-1,l);
        x -= l;
    }
    
    return ans;
}

int main(){
    long long n, x;
    cin >> n >> x;
    
    len[0] = 1;
    pat[0] = 1;
    
    for (int i = 1; i <= n; i++){
        len[i]= len[i-1]*2+3;
        pat[i] = pat[i-1]*2+1;
    }
    
    cout << solve(n,x) << endl;
    return 0;
}