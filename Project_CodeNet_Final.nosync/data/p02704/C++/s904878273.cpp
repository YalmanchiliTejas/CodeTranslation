#include <bits/stdc++.h>
using namespace std;

int nth_bit(uint64_t num, int n){
    return (num >> n) & 1;
}

uint64_t bit(int k){
    return 1ULL<<k;
}

void fail(){
    cout << -1 << endl;
    exit(0);
}

int main(){
    int N;
    cin >> N;
    vector<uint64_t> S(N), T(N), U(N), V(N);
    for(int i=0; i<N; i++) cin >> S[i];
    for(int i=0; i<N; i++) cin >> T[i];
    for(int i=0; i<N; i++) cin >> U[i];
    for(int i=0; i<N; i++) cin >> V[i];

    uint64_t ans[500][500] = {0};

    auto update = [](int& a, int b){
        if(a != -1 && a != b) fail();
        a = b;
    };

    for(int k=0; k<64; k++){
        vector<vector<int>> A(N, vector<int>(N, -1));
        vector<int> u(N), v(N);
        for(int i=0; i<N; i++){
            u[i] = nth_bit(U[i], k);
            v[i] = nth_bit(V[i], k);
        }

        for(int i=0; i<N; i++){
            if(S[i] != u[i]) for(int j=0; j<N; j++) update(A[i][j], u[i]);
        }
        for(int j=0; j<N; j++){
            if(T[j] != v[j]) for(int i=0; i<N; i++) update(A[i][j], v[j]);
        }

        vector<int> row[2], col[2], rows, cols, rows_ok, cols_ok;
        for(int i=0; i<N; i++){
            if(S[i] == u[i]){
                bool ok = false, m1 = false;
                for(int j=0; j<N; j++){
                    if(A[i][j] == u[i]) ok = true;
                    if(A[i][j] == -1) m1 = true;
                }
                if(!ok) row[u[i]].push_back(i), rows.push_back(i);
                if(ok && m1) rows_ok.push_back(i);
            }
        }
        for(int j=0; j<N; j++){
            if(T[j] == v[j]){
                bool ok = false, m1 = false;;
                for(int i=0; i<N; i++){
                    if(A[i][j] == v[j]) ok = true;
                    if(A[i][j] == -1) m1 = true;
                }
                if(!ok) col[v[j]].push_back(j), cols.push_back(j);
                if(ok && m1) cols_ok.push_back(j);
            }
        }

        if(rows_ok.size()){
            int r = rows_ok[0];
            for(int i=0; i<N; i++) for(int j=0; j<N; j++) if(A[i][j] == -1) A[i][j] = (i==r ? v[j] : u[i]);
        }else if(cols_ok.size()){
            int c = cols_ok[0];
            for(int i=0; i<N; i++) for(int j=0; j<N; j++) if(A[i][j] == -1) A[i][j] = (j!=c ? v[j] : u[i]);
        }else if(rows.size() == 0 && cols.size() == 0){
            // ok
        }else if(rows.size() > 1 && cols.size() > 1){
            int sr = rows.size(), sc = cols.size();
            for(int i=0; i<sr; i++) for(int j=0; j<sc; j++) A[rows[i]][cols[j]] = (i+j)%2;
        }else if(row[0].size() && row[1].size()){
            for(int i : rows) for(int j : cols) A[i][j] = u[i];
        }else if(col[0].size() && col[1].size()){
            for(int i : rows) for(int j : cols) A[i][j] = v[j];
        }else if( (row[0].size() && col[0].size()) || (row[1].size() && col[1].size())){
            for(int i : rows) for(int j : cols) A[i][j] = u[i];
        }else{
            fail();
        }

        for(int i=0; i<N; i++) for(int j=0; j<N; j++){
            assert(A[i][j] != -1);
            if(A[i][j]) ans[i][j] |= bit(k);
        }
    }

    for(int i=0; i<N; i++) for(int j=0; j<N; j++) cout << ans[i][j] << " \n"[j==N-1];

    for(int i=0; i<N; i++){
        auto v = ans[i][0];
        if(S[i] == 0){
            for(int j=0; j<N; j++) v &= ans[i][j];
        }else{
            for(int j=0; j<N; j++) v |= ans[i][j];
        }
        assert(v == U[i]);
    }

    for(int j=0; j<N; j++){
        auto v = ans[0][j];
        if(T[j] == 0){
            for(int i=0; i<N; i++) v &= ans[i][j];
        }else{
            for(int i=0; i<N; i++) v |= ans[i][j];
        }
        assert(v == V[j]);
    }
    return 0;
}
