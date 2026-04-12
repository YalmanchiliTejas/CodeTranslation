#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define pb push_back
#define ALL(obj) (obj).begin(), (obj).end()

using namespace std;
int N;
int H[25];
int main(){
    cin >> N;
    rep(i,N) cin >> H[i];
    int mx = H[0];
    int ct = 0;
    rep(i,N){
        if(H[i] >= mx){
            mx = H[i];
            ct++;
        }
    }
    
    cout << ct << endl;
    
}