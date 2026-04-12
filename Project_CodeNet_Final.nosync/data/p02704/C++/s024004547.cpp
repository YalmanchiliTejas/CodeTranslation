#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define REP(i,n) for (ll i = 0; i < (n); ++i)
#define RREP(i, n) for (ll i = (n) - 1; i >= 0; --i)
#define ALL(v) (v).begin(), (v).end()

void flip(vector<vector<ll>>& a){
    const ll n = a.size();
    REP(i, n){
        REP(j, i){
            swap(a.at(i).at(j), a.at(j).at(i));
        }
    }
}

bool solve(vector<vector<ll>>& a, const vector<vector<ll>>& s, const vector<vector<ll>>& u){
    const ll n = s.at(0).size();
    a.resize(n, vector<ll>(n, -1));

    vector<vector<ll>> rest(2);
    REP(i, 2){
        REP(j, n){
            if(s.at(i).at(j) != u.at(i).at(j)){
                REP(k, n){
                    if(a.at(j).at(k) == 1 - u.at(i).at(j)){ return false; }
                    a.at(j).at(k) = u.at(i).at(j);
                }
            }else{
                rest.at(i).push_back(j);
            }
        }
        flip(a);
    }

    if(rest.at(0).size() >= 2 && rest.at(1).size() >= 2){
        REP(i, rest.at(0).size()){
            const ll ri = rest.at(0).at(i);
            REP(j, rest.at(1).size()){
                const ll ci = rest.at(1).at(j);
                assert(a.at(ri).at(ci) == -1);
                a.at(ri).at(ci) = (i + j) % 2;
            }
        }
    }else if(rest.at(0).size() == 1 || rest.at(1).size() == 1){
        ll i = 0;
        if(rest.at(0).size() != 1){
            i = 1;
            flip(a);
        }

        assert(rest.at(i).size() == 1);
        const ll ri = rest.at(i).front();
        const ll val = s.at(i).at(ri) == 1;
        for(ll ci : rest.at(1 - i)){
            ll num1 = 0, num0 = 0;
            REP(j, n){
                if(a.at(j).at(ci) == 1){ num1++; }
                if(a.at(j).at(ci) == 0){ num0++; }
            }
            if(s.at(1 - i).at(ci) == 0 && num0 == 0){
                a.at(ri).at(ci) = 0;
            }else if(s.at(1 - i).at(ci) == 1 && num1 == 0){
                a.at(ri).at(ci) = 1;
            }else{
                a.at(ri).at(ci) = val;
            }
        }

        if(i == 1){
            flip(a);
        }
    }

    // check
    REP(i, 2){
        REP(j, n){
            ll tmp1 = 1, tmp2 = 0;
            REP(k, n){
                assert(a.at(j).at(k) != -1);
                tmp1 &= a.at(j).at(k);
                tmp2 |= a.at(j).at(k);
            }
            if(s.at(i).at(j) == 0 && tmp1 != u.at(i).at(j)){
                return false;
            }
            if(s.at(i).at(j) == 1 && tmp2 != u.at(i).at(j)){
                return false;
            }
        }
        flip(a);
    }
    return true;
}

int main(){
    ll n;
    cin >> n;
    vector<vector<ll>> s(2, vector<ll>(n));
    vector<vector<ull>> u(2, vector<ull>(n));
    REP(i, 2){
        REP(j, n){
            cin >> s.at(i).at(j);
        }
    }
    REP(i, 2){
        REP(j, n){
            cin >> u.at(i).at(j);
        }
    }

    vector<vector<ull>> a(n, vector<ull>(n, 0));
    REP(i, 64){
        vector<vector<ll>> tmp(n, vector<ll>(n, -1));
        vector<vector<ll>> ui(2, vector<ll>(n));
        REP(j, 2){
            REP(k, n){
                ui.at(j).at(k) = (u.at(j).at(k) >> i) & 1;
            }
        }
        if(!solve(tmp, s, ui)){
            cout << -1 << endl;
            return 0;
        }
        REP(j, n){
            REP(k, n){
                if(tmp.at(j).at(k) == 1){
                    a.at(j).at(k) += 1ULL << i;
                }
            }
        }
    }

    REP(i, n){
        REP(j, n){
            cout << a.at(i).at(j);
            if(j + 1 < n){
                cout << ' ';
            }else{
                cout << endl;
            }
        }
    }
    return 0;
}
