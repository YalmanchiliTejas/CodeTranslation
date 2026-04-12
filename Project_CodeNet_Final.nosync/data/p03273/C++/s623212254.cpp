#include<bits/stdc++.h>
//macros
using namespace std;
typedef long long ll;
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
vector<vector<char> > A;
vector<bool> B;
vector<bool> C;
int main(){
    int H,W;
    cin >> H >> W;
    A.resize(H);
    B.resize(H);
    C.resize(W);
    rep(i,0,H){
        A[i].resize(W);
        rep(j,0,W){
            char temp;
            cin >> temp;
            A[i][j] = temp;
            if(temp == '#'){
                B[i]=true;
                C[j]=true;
            }
        }
    }    
  
    rep(i,0,H){
        rep(j,0,W){
            if(B[i]==true && C[j]==true) cout << A[i][j];
        }
        if(B[i]==true) cout << endl;
    }
}