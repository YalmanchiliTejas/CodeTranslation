#include<bits/stdc++.h>
#define rep(i,f,n) for(int i = (f); (i) < (n); i++)
using namespace std;

int main(){

    int N; cin >> N;
    int hotels[N]; rep(i,0,N) cin >> hotels[i];
    int ans=1;
    int highst=hotels[0];

    rep(i,1,N){

        if(hotels[i]>=highst){
            highst = hotels[i];
            ans++;
        }

    }
    

    cout << ans << endl;
    
}
