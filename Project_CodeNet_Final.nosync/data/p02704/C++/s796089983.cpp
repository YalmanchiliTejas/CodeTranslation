#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long

int main() {
    int N;
    cin >> N;
    
    vector<int> S(N), T(N);
    vector<ll> U(N), V(N);
    for (int i = 0; i < N; i++) cin >> S[i];
    for (int i = 0; i < N; i++) cin >> T[i];
    for (int i = 0; i < N; i++) cin >> U[i];
    for (int i = 0; i < N; i++) cin >> V[i];
    
    if (N == 1) {
        if (U[0] == V[0]) cout << U[0] << endl;
        else cout << -1 << endl;
        return 0;
    }
    
    
    vector<vector<ll>> ans(N, vector<ll>(N, 0));
    
    for (int h = 0; h < 64; h++) {
        ll bit = 1;
        bit <<= h;
        vector<int> rlist, clist;
        bool rcheck = false, ccheck = false;
        int rcnt = 0, ccnt = 0;
        for (int i = 0; i < N; i++) {
            if (S[i] == 0 && (U[i]&bit) > 0) {
                for (int j = 0; j < N; j++) ans[i][j] |= bit;
                rcheck = true;
                rcnt++;
            }else if (!(S[i] == 1 && (U[i]&bit) == 0)) {
                rlist.push_back(i);
            }
        }
        
        for (int j = 0; j < N; j++) {
            if (T[j] == 0 && (V[j]&bit) > 0) {
                for (int i = 0; i < N; i++) ans[i][j] |= bit;
                ccheck = true;
                ccnt++;
            }else if (!(T[j] == 1 && (V[j]&bit) == 0)) {
                clist.push_back(j);
            }
        }
        
        if ((int)rlist.size() == 0 || (int)clist.size() == 0) continue;
        
        if ((int)rlist.size() == 1 && (int)clist.size() == 1) {
            int i = rlist[0], j = clist[0];
            if ((!rcheck && T[j] == 1) || (!ccheck && S[i] == 1)) ans[i][j] |= bit;
            continue;
        }
        
        if ((int)rlist.size() == 1) {
            int i = rlist[0];
            bool rmust = (S[i] == 1);
            for (int z = 0; z < (int)clist.size(); z++) {
                int j = clist[z];
                if (T[j] == 1 && !rcheck) ans[i][j] |= bit;
                if (rmust && !(T[j] == 0 && rcnt == N-1)) ans[i][j] |= bit; 
            }
            continue;
        }
        
        if ((int)clist.size() == 1) {
            int j = clist[0];
            bool cmust = (T[j] == 1);
            for (int z = 0; z < (int)rlist.size(); z++) {
                int i = rlist[z];
                if (S[i] == 1 && !ccheck) ans[i][j] |= bit;
                if (cmust && !(S[i] == 0 && ccnt == N-1)) ans[i][j] |= bit;
            }
            continue;
        }
        
        for (int k = 0; k < (int)rlist.size(); k++) {
            for (int l = 0; l < (int)clist.size(); l++) {
                if (k%2 == l%2) ans[rlist[k]][clist[l]] |= bit;
            }
        }
        
    }
    
    for (int i = 0; i < N; i++) {
        ll n = ans[i][0];
        for (int j = 1; j < N; j++) {
            if (S[i] == 0) n &= ans[i][j];
            else n |= ans[i][j];
        }
        if (n != U[i]) {
            cout << -1 << endl;
            return 0;
        }
    }
    
    for (int j = 0; j < N; j++) {
        ll n = ans[0][j];
        for (int i = 1; i < N; i++) {
            if (T[j] == 0) n &= ans[i][j];
            else n |= ans[i][j];
        }
        if (n != V[j]) {
            cout << -1 << endl;
            return 0;
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << ans[i][j] << ((j < N-1) ? " " : "\n");
        }
    }
    return 0;
}
