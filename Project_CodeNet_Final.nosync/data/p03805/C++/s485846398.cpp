#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(v) v.begin(),v.end()

using namespace std;
typedef long long ll;


int N,M;
vector<vector<int> > V;
vector<int> perm;



int main(){
    
    cin >> N >> M;
    V.assign(N+1, vector<int>(N+1, 0));
    rep(i,M){
        int a,b;
        cin >> a >> b;
        V[a][b] = 1;
        V[b][a] = 1;
    }
    rep(i,N-1) perm.push_back(i+2);
    
    int ans = 0;
    
    do{
        bool aa = true;
        if (V[1][perm[0]] == 1) {
            rep(i,N-2){
                
                if (V[perm[i]][perm[i+1]] == 0) {
                    aa = false;
                    break;
                }

            }
            
            if (aa) {
                ans += 1;
            }
        }
        
        
        
        
    }while (next_permutation(all(perm)));
    
    cout << ans << endl;
    
    return 0;

}
