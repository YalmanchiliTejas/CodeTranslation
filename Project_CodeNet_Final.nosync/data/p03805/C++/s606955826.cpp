#include<iostream>
#include<vector>
using namespace std;
int ans = 0;
int n;
int m;
vector<vector<int> > ab(9,vector<int> (0,0));
bool c[8];

void solve(int i){
        int n_false=0;
        for(int k =0;k<n;k++){
             if(c[k] == false){
                n_false ++;
            }
        }   
        if(n_false == 0){
            ans ++;
            return;
            }
        
    for(int j=0;j<ab[i].size();j++){
        if(c[ab[i][j]-1] == false){
            c[ab[i][j]-1] = true;
            solve(ab[i][j]);
            c[ab[i][j]-1] =false; 
        }
        
    }
}

int main(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        ab[a].push_back(b);
        ab[b].push_back(a);
    }
    for(int j=1;j<=n;j++){
        c[j] = false;
    }
    c[0] = true;
    solve(1);
    cout << ans << endl;
}