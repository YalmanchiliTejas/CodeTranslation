#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define pb(a) push_back(a)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;
using P  = pair<int,int>;
using vP = vector<P>;

int main(){
    int h,w;
    cin>>h>>w;
    
    vector<string> a(h);
    rep(i,h)cin>>a[i];
    
    if(a[0][0]!='#'){
        cout << "Impossible" << endl;
        return 0;
    }
    
    bool ok = true;
    int ni = 0, nj = 0;
    a[0][0] = '.';
    
    vi di = {1,0};
    vi dj = {0,1};
    
    while(ok && (!(ni==h-1 && nj==w-1))){
        
        ok = false;
        
        rep(k,2){
            int ai = ni + di[k];
            int aj = nj + dj[k];
            
            if(ai>=h || aj>=w)continue;
            
            if(a[ai][aj]=='#'){
                
                a[ai][aj] = '.';
                ni = ai;
                nj = aj;
                ok = true;
                
                break;
            }
        }
    }
    
    rep(i,h)rep(j,w){
        if(a[i][j]!='.'){
            cout << "Impossible" << endl;
            return 0;
        }
    }
    cout << "Possible" << endl;
    
    return 0;
}