#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
using P = pair<int, int>;
using P3 = pair<int,P>;
using PP = pair<P, P>;
constexpr int INF = 1<<30;
constexpr ll MOD = ll(1e9)+7;
constexpr int di[] = {0,1,0,-1};
constexpr int dj[] = {1,0,-1,0};

bool solve(){
    int m, n;
    cin >> m >> n;
    if(m == 0) return false;
    vector<int> a(m);
    for(int i=0;i<m;i++){
        a[i] = i+1;
    }
    for(int t=1,idx=0;t<=n;t++){
        string s;
        cin >> s;
        bool ok = true;
        if(t%3==0 && t%5==0){
            ok &= s == "FizzBuzz";
        }else if(t%3==0){
            ok &= s == "Fizz";
        }else if(t%5==0){
            ok &= s == "Buzz";
        }else{
            ok &= s == to_string(t);
        }
        if(!ok && a.size() > 1){
            a.erase(a.begin()+idx);
        }else{
            idx++;
        }
        if(idx>=a.size()){
            idx = 0;
        }
    }
    for(int i=0;i<a.size();i++){
        cout << a[i] << " \n"[i+1==a.size()];
    }
    return true;
}

int main(){
    while(solve());
    return 0;
}

