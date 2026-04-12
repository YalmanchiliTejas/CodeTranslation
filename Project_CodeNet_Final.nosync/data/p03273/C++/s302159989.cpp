#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
const int INF = 1e9;
const ll INFll = 1e18;
#define put(n) cout<<(n)<<endl
#define Cout(n) cout<<(n)
#define FOR(i,num,N) for(int(i)=(num);(i)<(N);++(i))
#define RFOR(i,num,N) for(int (i)=(num);(i)>(N);--(i))
#define all(v) (v).begin() , (v).end()
#define rall(v) (v).rbegin() , (v).rend()
#define MP make_pair
#define pb(q) push_back(q)
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int H,W;
    cin>>H>>W;
    vector<vector<char>> C(H,vector<char>(W));
    vector<int> I(H,0),J(W,0);

    FOR(i,0,H){
        bool ok = false;
        FOR(j,0,W){
            cin>>C[i][j];
            if(C[i][j] == '#') ok = true; 
        }
        if(!ok) I[i] = 1;
    }

    FOR(j,0,W){
        bool ok = false;
        FOR(i,0,H){
            if(C[i][j] == '#') ok = true;
        }
        if(!ok) J[j] = true;
    }

    FOR(i,0,H){
        if(I[i]) continue;
        FOR(j,0,W){
            if(J[j]) continue;
            cout<<C[i][j];
        }
        cout<<endl;
    }



}