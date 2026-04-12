#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

typedef long double ld;

ull mat[505][505];
ull S[505];
ull T[505];
ull U[505];
ull V[505];
ull color[505];
ull coland[505];
ull rowand[505];
ull rowor[505];
int pom[505][505];
bool imarow[2][505];
bool imacol[2][505];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    ll n;
    cin >> n;
    for(ll i=1; i<=n; i++){
        cin >> S[i];
    }
    for(ll i=1; i<=n; i++){
        cin >> T[i];
    }
    for(ll i=1; i<=n; i++){
        cin >> U[i];
    }
    for(ll i=1; i<=n; i++){
        cin >> V[i];
    }
    for(ll k=63; k>=0; k--){
        ull g;
        if(k == 63){
            g = (1LL<<62);
            g *= 2;
        }
        else g = (1LL<<k);
        ll oi = n, oj = n;
        for(ll i=1; i<=n; i++){
            if(S[i] == 1 && (U[i]&g) == 0) oi--;
            if(S[i] == 0 && (U[i]&g) != 0) oi--;
            if(T[i] == 1 && (V[i]&g) == 0) oj--;
            if(T[i] == 0 && (V[i]&g) != 0) oj--;
            imarow[0][i] = imarow[1][i] = imacol[1][i] = imacol[0][i] = 0;
        }
        for(ll i=1; i<=n; i++){
            for(ll j=1; j<=n; j++){
                ull a = (U[i] & g) > 0;
                ull b = (V[j] & g) > 0;
                pom[i][j] = -1;
                if(S[i] == 1 && a == 0){
                    pom[i][j] = 0;
                    imarow[0][i] = 1;
                    imacol[0][j] = 1;
                }
                if(S[i] == 0 && a){
                    //cout << "ovde\n";
                    pom[i][j] = 1;
                    imarow[1][i] = 1;
                    imacol[1][j] = 1;
                }
                if(T[j] == 1 && b == 0){
                    if(pom[i][j] == 1){
                        cout << -1;
                        return 0;
                    }
                    pom[i][j] = 0;
                    imarow[0][i] = 1;
                    imacol[0][j] = 1;
                }
                if(T[j] == 0 && b){
                    if(pom[i][j] == 0){
                        cout << -1;
                        return 0;
                    }
                    pom[i][j] = 1;
                    imarow[1][i] = 1;
                    imacol[1][j] = 1;
                }
            }
        }
        if(oi >= 2 && oj >= 2){
            ll poc = 1;
            for(ll i=1; i<=n; i++){
                poc ^= 1;
                ll tren = poc;
                for(ll j=1; j<=n; j++){
                    if(pom[i][j] == -1){
                        pom[i][j] = tren;
                        tren ^= 1;
                    }
                }
            }
        }
        else if(oi == 1){
            //if(k == 0) cout << "ove je" << endl;
            for(ll i=1; i<=n; i++){
                for(ll j=1; j<=n; j++){
                    //if(k == 0) cout << pom[i][j] << " ";
                    if(pom[i][j] == -1){
                        if(T[j] == 0){
                            //if(k == 0) cout << "e znaci " << imacol[0][j] << endl;
                            if(imacol[0][j]) continue;
                            imacol[0][j] = 1;
                            pom[i][j] = 0;
                        }
                        else{
                            if(imacol[1][j]) continue;
                            imacol[1][j] = 1;
                            pom[i][j] = 1;
                        }
                    }
                }
                //if(k == 0) cout << endl;
            }
            for(ll i=1; i<=n; i++){
                for(ll j=1; j<=n; j++){
                    //if(k == 0) cout << pom[i][j] << " ";
                    if(pom[i][j] == -1){
                        if(S[i] == 0){
                            pom[i][j] = 0;
                        }
                        else{
                            pom[i][j] = 1;
                        }
                    }
                }
                //if(k == 0) cout << endl;
            }
        }
        else{
            for(ll i=1; i<=n; i++){
                for(ll j=1; j<=n; j++){
                    if(pom[i][j] == -1){
                        if(S[i] == 0){
                            if(imarow[0][i]) continue;
                            imarow[0][i] = 1;
                            pom[i][j] = 0;
                        }
                        else{
                            if(imarow[1][i]) continue;
                            imarow[1][i] = 1;
                            pom[i][j] = 1;
                        }
                    }
                }
            }
            for(ll i=1; i<=n; i++){
                for(ll j=1; j<=n; j++){
                    if(pom[i][j] == -1){
                        if(T[j] == 0){
                            pom[i][j] = 0;
                        }
                        else{
                            pom[i][j] = 1;
                        }
                    }
                }
            }
        }
        for(ll i=1; i<=n; i++){
            for(ll j=1; j<=n; j++){
                //cout << pom[i][j] << " ";
                if(pom[i][j]) mat[i][j] |= g;
            }
            //cout << "\n";
        }
    }
    for(ll i=1; i<=n; i++){
        rowand[i] = mat[i][1];
        coland[i] = mat[1][i];
    }
    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=n; j++){
            coland[j] &= mat[i][j];
            color[j] |= mat[i][j];
            rowand[i] &= mat[i][j];
            rowor[i] |= mat[i][j];
        }
    }
    for(ll i=1; i<=n; i++){
        if(S[i] == 0 && rowand[i] != U[i]){
            cout << -1;
            return 0;
        }
        if(S[i] == 1 && rowor[i] != U[i]){
            cout << -1;
            return 0;
        }
        if(T[i] == 0 && coland[i] != V[i]){
            cout << -1;
            return 0;
        }
        if(T[i] == 1 && color[i] != V[i]){
            cout << -1;
            return 0;
        }
    }
    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=n; j++){
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
