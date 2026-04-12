#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<unsigned long long int>> ans;
vector<vector<int>> bit;
vector<int> s, t;
vector<unsigned long long int> u, v;
vector<int> ub, vb;

bool solve(){
    // first fix as much as possible
    for(int i=0; i<n; i++){
        if((s[i] == 0 && ub[i] == 1)// AND, 1 : all 1
        || (s[i] == 1 && ub[i] == 0)// OR , 0 : all 0
        ){
            for(int j=0; j<n; j++){
                //cout << bit[i][j] << " " << ub[i] << endl;
                if(bit[i][j] != -1
                && bit[i][j] != ub[i]) return false;

                // if bit[i][j] = -1
                bit[i][j] = ub[i];
            }
        }
    }
    for(int j=0; j<n; j++){
        if((t[j] == 0 && vb[j] == 1)// AND, 1 : all 1
        || (t[j] == 1 && vb[j] == 0)// OR , 0 : all 0
        ){
            for(int i=0; i<n; i++){
                if(bit[i][j] != -1
                && bit[i][j] != vb[j]) return false;
                
                // if bit[i][j] = -1
                bit[i][j] = vb[j];
            }
        }
    }

    // for remaining undetermined cells
    bool update = true;
    while(update == true){
        update = false;

        for(int i=0; i<n; i++){
            bool check = false;// whether already confirmed
            vector<int> undetermined;

            if((s[i] == 0 && ub[i] == 0)// AND, 0 : at least one 0
            || (s[i] == 1 && ub[i] == 1)// OR , 1 : at least one 1
            ){
                for(int j=0; j<n; j++){
                    if(bit[i][j] != -1
                    && bit[i][j] == ub[i]) check = true;

                    else if(bit[i][j] == -1) undetermined.push_back(j);
                }
                if(check == true) continue;// move on to the next i
                if(check == false && undetermined.size() == 0) return false;
                if(check == false && undetermined.size() == 1){
                    bit[i][undetermined[0]] = ub[i];
                    update = true;
                }
            }
        }
        for(int j=0; j<n; j++){
            bool check = false;// whether already confirmed
            vector<int> undetermined;

            if((t[j] == 0 && vb[j] == 0)// AND, 0 : at least one 0
            || (t[j] == 1 && vb[j] == 1)// OR , 1 : at least one 1
            ){
                for(int i=0; i<n; i++){
                    if(bit[i][j] != -1
                    && bit[i][j] == vb[j]) check = true;

                    else if(bit[i][j] == -1) undetermined.push_back(i);
                }
                if(check == true) continue;// move on to the next j
                if(check == false && undetermined.size() == 0) return false;
                if(check == false && undetermined.size() == 1){
                    bit[undetermined[0]][j] = vb[j];
                    update = true;
                }
            }
        }
    }

    // for yet undetermined cells
    vector<int> udi, udj;
    for(int i=0; i<n; i++){
        bool check = true;
        for(int j=0; j<n; j++){
            if(bit[i][j] == -1) check = false;
        }
        if(check == false) udi.push_back(i);
    }
    for(int j=0; j<n; j++){
        bool check = true;
        for(int i=0; i<n; i++){
            if(bit[i][j] == -1) check = false;
        }
        if(check == false) udj.push_back(j);
    }
    for(int i=0; i<udi.size(); i++){
        for(int j=0; j<udj.size(); j++){
            bit[udi[i]][udj[j]] = (i+j) % 2;// checker board
        }
        //cout << endl;
    }
    return true;
}

int main(){
    cin >> n;
    ans.resize(n, vector<unsigned long long int>(n));
    s.resize(n); t.resize(n);
    u.resize(n); v.resize(n);
    ub.resize(n); vb.resize(n);

    for(int i=0; i<n; i++) cin >> s[i];
    for(int i=0; i<n; i++) cin >> t[i];
    for(int i=0; i<n; i++) cin >> u[i];
    for(int i=0; i<n; i++) cin >> v[i];

    for(int b=0; b<64; b++){
        for(int i=0; i<n; i++){
            ub[i] = (u[i] >> b & 1);
            vb[i] = (v[i] >> b & 1);
        }
        bit.assign(n, vector<int>(n, -1));
        if(solve() == false){
            cout << -1 << endl;
            return 0;
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(bit[i][j] == 1){
                    ans[i][j] |= (1ULL) << b;
                }
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << ans[i][j];
            if(j == n-1) break;
            cout << " ";
        }
        cout << endl;
    }
    return 0;
}