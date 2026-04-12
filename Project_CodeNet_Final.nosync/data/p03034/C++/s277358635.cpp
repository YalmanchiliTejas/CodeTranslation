#include <bits/stdc++.h>
using namespace std;

long long n;
vector<long long> s;

long long solve();

int main(){
    cin >> n;
    s.resize(n);
    for(int i = 0;i < n;++i)cin >> s[i];
    cout << solve() << endl;
    return 0;
}

long long solve(){
    long long ans = 0;
    for(int i = 1;i < n;++i){
        long long nowx = 0,nowy = n -1,nowc = 0;
        while(i < nowy){
            nowc += s[nowx] + s[nowy];
            ans = max(ans,nowc);
            nowx += i;
            nowy -= i;
            if(nowy % i == 0 && nowx >= nowy)break;
        }
    }
    return ans;
}