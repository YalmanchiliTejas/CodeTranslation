#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define ff first
#define ss second
#define sz(x) (int)x.size()
#define all(x) (x).begin(),(x).end()
#define F(i,x,n,y) for(i=x;i<n;i+=y)
#define fi(i,x,n) for(i=x;i<n;++i)
#define f(n) for(int i=0;i<n;++i)
#define fr(i,x,n) for(i=x;i>=n;--i)
#define endl '\n'

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
int r[110],c[110];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x,y;
    cin>>x>>y;
    char g[110][110];
    int i,j;
    fi(i,1,x+1){
        fi(j,1,y+1)
            cin>>g[i][j];
    }
    fi(i,1,x+1){
        fi(j,1,y+1){
            if(g[i][j]=='#'){
                r[i]=1;
                break;
            }
        }
    }
    fi(i,1,y+1){
        fi(j,1,x+1){
            if(g[j][i]=='#'){
                c[i]=1;
                break;
            }
        }
    }

    fi(i,1,x+1){
        bool bad=false;
        fi(j,1,y+1){
            if(!r[i]){
             bad=true;
                break;
            }
            if(!c[j]) continue;
            cout<<g[i][j];
        }
        if(!bad)
            cout<<endl;
    }

    return 0;
}

