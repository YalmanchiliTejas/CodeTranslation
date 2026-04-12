#include<bits/stdc++.h>

int main(){
    using namespace std;
    unsigned long N;
    cin >> N;
    vector<unsigned long> S(N), T(N);
    vector U(64, vector(N, 0UL)), V(64, vector(N, 0UL));
    for(auto&& i : S){
        cin >> i;
        i ^= 1;
    }
    for(auto&& i : T){
        cin >> i;
        i ^= 1;
    }
    vector<unsigned long> u(N), v(N);
    for(auto&& i : u)cin >> i;
    for(auto&& i : v)cin >> i;
    for(unsigned long i{0}; i < 64; ++i)for(unsigned long j{0}; j < N; ++j)U[63 - i][j] = (S[j] ^ (u[j] >> i)) & 1;
    for(unsigned long i{0}; i < 64; ++i)for(unsigned long j{0}; j < N; ++j)V[63 - i][j] = (T[j] ^ (v[j] >> i)) & 1;
    vector A(N, vector(N, 0UL));
    for(unsigned long i{0}; i < 64; ++i){
        for(auto&& _ : A)for(auto&& j : _)j *= 2;
        unsigned long x{accumulate(U[i].begin(), U[i].end(), 0UL)}, y{accumulate(V[i].begin(), V[i].end(), 0UL)};
        vector<unsigned long> xd(2), yd(2);
        for(unsigned long j{0}; j < N; ++j)if(!U[i][j])xd[S[j]] |= 1;
        for(unsigned long j{0}; j < N; ++j)if(!V[i][j])yd[T[j]] |= 1;
        if((xd[0] && yd[1]) || (xd[1] && yd[0]))return 0 & puts("-1");
        if((x > 1 && y > 1) || (x == 0 || y == 0)){
            for(unsigned long _i{0}, _cx{0}; _i < N; ++_i)if(U[i][_i]){
                _cx ^= 1;
                for(unsigned long _j{0}, _cy{0}; _j < N; ++_j){
                    if(V[i][_j]){
                        _cy ^= 1;
                        A[_i][_j] += _cx ^ _cy;
                    }else A[_i][_j] += V[i][_j] ^ T[_j];
                }
            }else for(unsigned long _j{0}; _j < N; ++_j)A[_i][_j] += U[i][_i] ^ S[_i];
            continue;
        }
        if(xd[0] + xd[1] + yd[0] + yd[1] == 2){
            if((xd[0] && xd[1]) || (yd[0] && yd[1])){
                if(x == 1){
                    for(unsigned long _i{0}; _i < N; ++_i)if(U[i][_i])for(unsigned long _j{0}; _j < N; ++_j){
                        if(V[i][_j])A[_i][_j] += U[i][_i] ^ S[_i];
                        else A[_i][_j] += V[i][_j] ^ T[_j];
                    }else for(unsigned long _j{0}; _j < N; ++_j)A[_i][_j] += U[i][_i] ^ S[_i];
                }else{
                    for(unsigned long _i{0}; _i < N; ++_i)for(unsigned long _j{0}; _j < N; ++_j)if(V[i][_j]){
                        if(U[i][_i])A[_i][_j] += V[i][_j] ^ T[_j];
                        else A[_i][_j] += U[i][_i] ^ S[_i];
                    }else A[_i][_j] += V[i][_j] ^ T[_j];
                }
            }else{
                for(unsigned long _i{0}; _i < N; ++_i)for(unsigned long _j{0}; _j < N; ++_j)A[_i][_j] += (V[i][_j] && U[i][_i]) ^ xd[1];
            }
            continue;
        }
        if(x == 1){
            for(unsigned long _i{0}; _i < N; ++_i)if(U[i][_i])for(unsigned long _j{0}; _j < N; ++_j){
                if(xd[V[i][_j] ^ T[_j]])A[_i][_j] += U[i][_i] ^ S[_i];
                else A[_i][_j] += V[i][_j] ^ T[_j];
            }else for(unsigned long _j{0}; _j < N; ++_j)A[_i][_j] += U[i][_i] ^ S[_i];
        }else{
            for(unsigned long _i{0}; _i < N; ++_i)for(unsigned long _j{0}; _j < N; ++_j)if(V[i][_j]){
                if(yd[U[i][_i] ^ S[_i]])A[_i][_j] += V[i][_j] ^ T[_j];
                else A[_i][_j] += U[i][_i] ^ S[_i];
            }else A[_i][_j] += V[i][_j] ^ T[_j];
        }
    }
    [&N, &A, &S, &T, &u, &v]{
        for(unsigned long i{0}; i < N; ++i)if(S[i]){
            unsigned long x{A[i][0]};
            for(unsigned long j{0}; j < N; ++j)x &= A[i][j];
            if(x != u[i])exit(0 & puts("-1"));
        }else{
            unsigned long x{A[i][0]};
            for(unsigned long j{0}; j < N; ++j)x |= A[i][j];
            if(x != u[i])exit(0 & puts("-1"));
        }
        for(unsigned long j{0}; j < N; ++j)if(T[j]){
            unsigned long y{A[0][j]};
            for(unsigned long i{0}; i < N; ++i)y &= A[i][j];
            if(y != v[j])exit(0 & puts("-1"));
        }else{
            unsigned long y{A[0][j]};
            for(unsigned long i{0}; i < N; ++i)y |= A[i][j];
            if(y != v[j])exit(0 & puts("-1"));
        }
        //puts("correct!");
    }();
    for(const auto& _ : A){
        for(const auto& j : _)cout << j << " ";
        cout << endl;
    }
    return 0;
}