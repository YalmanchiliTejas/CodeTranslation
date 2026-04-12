#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef unsigned long long ll;
typedef double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) ((unsigned long long)(1)<<x)
const ll DIM = 500+7;
const ll INF = 10E17;
const ll MOD = 2019;
const ll LOG = 64;
const unsigned long long masksz = po(64)-1;
ll S[DIM],T[DIM],U[DIM],V[DIM],A[DIM][DIM];
ll cntro[DIM][LOG+7],cntcol[DIM][LOG+7];
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    forn(i,n)cin>>S[i];
    forn(i,n)cin>>T[i];
    forn(i,n)cin>>U[i];
    forn(i,n)cin>>V[i];
    forn(pos,n){
        ll x = U[pos];
        vector<ll> bit;
        forn(i,LOG){
            bit.pb(x%2);
            x/=2;
        }
        if (S[pos]==0){

            forn(i,n){
                ll mult = 1;
                forn(j,LOG){
                    if (bit[j-1]==0){
                        mult*=2;
                        continue;
                    }
                    if (!(A[pos][i]&mult)){
                        cntro[pos][j]++;
                        cntcol[i][j]++;
                        A[pos][i]|=mult;
                    }
                    mult*=2;
                }

            }
        }
        x = V[pos];
        bit.clear();
        forn(i,LOG){
            bit.pb(x%2);
            x/=2;
        }
        if (T[pos]==0){

            forn(i,n){
                ll mult = 1;
                forn(j,LOG){
                    if (bit[j-1]==0){
                        mult*=2;
                        continue;
                    }
                    if (!(A[i][pos]&mult)){
                        cntcol[pos][j]++;
                        cntro[i][j]++;
                        A[i][pos]|=mult;
                    }
                    mult*=2;
                }

            }
        }


    }
    forn(pos,n){
        ll x = U[pos];
        vector<ll> bit;
        forn(i,LOG){
            bit.pb(x%2);
            x/=2;
        }

        if (S[pos]==1){
            ll mult = 1;
            forn(j,LOG){
                if (bit[j-1]==0){
                    mult*=2;
                    continue;
                }
                ll flag = 0;
                forn(i,n){
                    if (A[pos][i]&mult){
                        flag = 1;
                        break;
                    }
                }
                if (flag==0){
                    forn(i,n){
                        if(T[i]==1 && (V[i]&mult)){
                            if (!(A[pos][i]&mult)){
                                cntcol[i][j]++;
                                cntro[pos][j]++;
                            }
                            A[pos][i]|=mult;
                            flag =1;
                            break;
                        }
                    }
                    if (flag==0)
                    forn(i,n){
                        if (T[i]==0 && cntcol[i][j]<n-1 ){
                            if (!(A[pos][i]&mult)){
                                cntcol[i][j]++;
                                cntro[pos][j]++;
                            }
                            A[pos][i]|=mult;
                            break;
                        }

                    }
                }
                mult*=2;
            }

        }
        x = V[pos];
        bit.clear();
        forn(i,LOG){
            bit.pb(x%2);
            x/=2;
        }
        if (T[pos]==1){
            ll mult = 1;
            forn(j,LOG){
                if (bit[j-1]==0){
                    mult*=2;
                    continue;
                }
                ll flag = 0;
                forn(i,n){
                    if (A[i][pos]&mult){
                        flag = 1;
                        break;
                    }
                }
                if (flag==0){
                    forn(i,n){
                        if(S[i]==1 && (U[i]&mult)){
                            if (!(A[i][pos]&mult)){
                                cntro[i][j]++;
                                cntcol[pos][j]++;
                            }
                            A[i][pos]|=mult;
                            flag = 1;
                            break;
                        }
                    }
                    if (flag==0)
                    forn(i,n){
                        if (S[i]==0 && cntro[i][j]<n-1 ){
                            if (!(A[i][pos]&mult)){
                                cntro[i][j]++;
                                cntcol[pos][j]++;
                            }
                            A[i][pos]|=mult;
                            break;
                        }

                    }
                }
                mult*=2;
            }

        }
    }
    forn(i,n){
        ll r[2];
        r[0] = A[i][1];r[1] = A[i][1];
        forn(j,n){
            r[0]&=A[i][j];
            r[1]|=A[i][j];
        }
        if (r[S[i]]!=U[i]){
            cout<<"-1\n";
            return 0;
        }
    }
    forn(j,n){
        ll r[2];
        r[0] = A[1][j];
        r[1] = A[1][j];
        forn(i,n){
            r[0]&=A[i][j];
            r[1]|=A[i][j];
        }
        if (r[T[j]]!=V[j]){
            cout<<"-1\n";
            return 0;
        }
    }
    forn(i,n){
        forn(j,n){
            cout<<A[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}
