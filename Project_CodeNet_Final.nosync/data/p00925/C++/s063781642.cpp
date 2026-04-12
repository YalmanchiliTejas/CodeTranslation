#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;


ll getv(string& S,int& i){
    ll ret = 0;
    while(S[i]>='0'&&S[i]<='9'){
        ret = ret * 10 + (S[i]-'0');
        i++;
    }
    return ret;
}
ll rule1(string S){
    ll ret = 0;
    vector<ll> type;
    vector<ll> vals;
    int i = 0;
    while(i < S.length()){
        ll val = getv(S,i);
        vals.push_back(val);
        if(i == S.length()) break;
        if(S[i] == '+') type.push_back(0);
        else type.push_back(1);
        
        i++;
    }
    
//    for(auto v:type) cout << v << " "; cout << endl;
//    for(auto v:vals) cout << v << " "; cout << endl;
    
    while(true){
        bool update = false;
        for(int i = 0; i < type.size();i++){
            if(type[i] == 1){
                update = true;
                vals[i] *= vals[i+1];
                type.erase(type.begin()+i);
                vals.erase(vals.begin()+i+1);
                break;
            }
        }
        if(update) continue;
        break;
    }
    
    ret = accumulate(vals.begin(), vals.end(), 0LL);
    return ret;
}
ll rule2(string S){
    ll ret = 0;
    vector<ll> type;
    vector<ll> vals;
    int i = 0;
    while(i < S.length()){
        ll val = getv(S,i);
        vals.push_back(val);
        if(i == S.length()) break;
        if(S[i] == '+') type.push_back(0);
        else type.push_back(1);
        
        i++;
    }
    
    ret = vals.front();
    for(int i = 0; i < type.size();i++){
        if(type[i]==1){
            ret *= vals[i+1];
        }else{
            ret += vals[i+1];
        }
    }
    
    return ret;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    string S; cin >> S;
    ll A; cin >> A;
    
    ll r1 = rule1(S);
    ll r2 = rule2(S);
    
    bool f1 = r1 == A, f2 = r2 == A;
    
    if(f1&&!f2) cout << "M" << endl;
    else if(!f1&&f2) cout << "L" << endl;
    else if(f1&&f2) cout << "U" << endl;
    else cout << "I" << endl;
    return 0;
}

