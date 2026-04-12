#include<bits/stdc++.h>

#define ll unsigned long long
#define fornum(A,B,C) for(A=B;A<C;++A)
#define pii pair<int,int>
#define pll pair<ll,ll>

using namespace std;

/////////////////////////////////////////////////////

ll N;
ll S[555], T[555];
ll U[555], V[555];
ll  mks[555],mkt[555];
ll A[555][555];
ll i, j, k;

void outpt(){
    fornum(i,0,N){
        ll a = A[i][0];
        fornum(j,1,N){
            if(S[i]==0){
                a &= A[i][j];
            }else{
                a |= A[i][j];
            }
        }
        if(a!=U[i]){
            break;
        }
        a = A[0][i];
        fornum(j,1,N){
            if(T[i]==0){
                a &= A[j][i];
            }else{
                a |= A[j][i];
            }
        }
        if(a!=V[i])
            break;
    }
    if(i<N){
        printf("-1\n");
        return;
    }
    fornum(i,0,N){
        fornum(j,0,N){
            cout << A[i][j]<<" ";
        }
        cout << endl;
    }
}


int main(){
    cin>>N;
    fornum(i,0,N){
        cin>>S[i];
    }
    fornum(i,0,N){
        cin>>T[i];
    }
    fornum(i,0,N){
        cin>>U[i];
    }
    fornum(i,0,N){
        cin >> V[i];
    }
    //r&
    fornum(i,0,N){
        if(S[i]==1)
            continue;
        fornum(j,0,N){
            A[i][j] |= U[i];
        }
    }
    //c&
    fornum(i,0,N){
        if(T[i]==1)
            continue;
        fornum(j,0,N){
            A[j][i] |= V[i];
        }
    }
    //r|
    k = 0;
    fornum(i,0,N){
        if(S[i]==0)
            continue;
        fornum(j,0,N){
            if(T[j]==1){
                A[i][j] = U[i] & V[j];
            }
        }
        ll aa = 0;
        fornum(j,0,N){
            aa |= A[i][j];
        }
        if((aa&U[i])!=U[i]){
            ll a = 1e9, b = 1e9;
            fornum(j,0,N){
                if(T[j]==0){
                    if(a==1e9)
                        a = j;
                    b = j;
                }
            }
            if(a==1e9)
                continue;
            ll c = (aa & U[i]) ^ U[i];
            if(k%2==0){
                A[i][a] |= c;
            }else{
                A[i][b] |= c;
            }
        }
        ++k;
    }
    k = 0;
    fornum(i,0,N){
        if(T[i]==0)
            continue;
        ll aa = 0;
        fornum(j,0,N){
            aa |= A[j][i];
        }
        if((aa&V[i])!=V[i]){
            ll a = 1e9, b = 1e9;
            fornum(j,0,N){
                if(S[j]==0){
                    if(a==1e9)
                        a = j;
                    b = j;
                }
            }
            if(a==1e9)
                continue;
            ll c = (aa & V[i]) ^ V[i];
            if(k%2==0){
                A[a][i] |= c;
            }else{
                A[b][i] |= c;
            }
        }
        ++k;
    }

    outpt();

    return 0;
}