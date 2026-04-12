#include<bits/stdc++.h>
#define R(i) for(I i=0;i<n;i++)
#define L R(i)
#define C cin>>
#define A a[i][j]
#define X for(I i : x)
#define Y for(I j : y)
using namespace std;
using U=uint64_t;
using I=int;
const I N=500;
I n,f,s[N],t[N],u[N],v[N],a[N][N];
U b[N][N];
void end(){
    puts("-1");
    exit(0);
}
void solve(){
    memset(a,7,1e6);
    vector<I> x(n), y(n);
    auto px = x.begin(), py = y.begin();
    L x[i] = y[i] = i;
    L{
        if(s[i] ^ u[i]){
            R(j) A = u[i];
            px = x.erase(px);
        }
        else px++;
    }
    R(j){
        if(t[j] ^ v[j]){
            L{
                if(!(A^v[j]^1)) end();
                A = v[j];
            }
            py = y.erase(py);
        }
        else py++;
    }
    if(x.size() > 1 && y.size() > 1){
        f=0;
        X{
            I c=f;
            Y{
                A = c;
                c^=1;
            }
            f^=1;
        }
    }
    else if(x.size() == 1){
        I i = x[0];
        Y{
            A = u[i];
            f = 1;
            L if(A == v[j]) f = 0;
            if(f) A = v[j];
        }
    }
    else if(y.size() == 1){
        I j = y[0];
        X{
            A = v[j];
            f = 1;
            R(j) if(A == u[i]) f = 0;
            if(f) A = u[i];
        }
    }
    X{
        f = 1;
        R(j) if(A == u[i]) f = 0;
        if(f) end();
    }
    Y{
        f = 1;
        L if(A == v[j]) f = 0;
        if(f) end();
    }
}
I main(){
    C n;
    vector<U> U(n), V(n);
    L C s[i];
    L C t[i];
    L C U[i];
    L C V[i];
    for(I d=64;d--;){
        L u[i] = U[i] >> d & 1;
        L v[i] = V[i] >> d & 1;
        solve();
        L R(j)b[i][j]=b[i][j]*2|A;
    }
    L{
        R(j) cout << b[i][j] << ' ';
        puts("");
    }
}