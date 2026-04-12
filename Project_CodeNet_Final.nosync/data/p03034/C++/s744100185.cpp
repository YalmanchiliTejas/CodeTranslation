#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> sumst[100100]; //sumst[C][k]にはスタートから間隔Cでk個の和を取った値を入れておく
vector<ll> sumla[100100]; //sumla[C][k]にはゴール....

int main(){
    int N; cin >> N;
    ll s[100100];
    for(int i=0; i<N; i++){
        cin >> s[i];
    }

    for(int C=1; C<N; C++){
        int k=(N-1)/C;
        sumst[C].push_back(0LL);
        for(int i=0; i<k; i++){
            ll a =sumst[C].at(i)+s[(i+1)*C];
            sumst[C].push_back(a);
        }
    }

    for(int C=1; C<N; C++){
        int k=(N-1)/C;
        sumla[C].push_back(0LL);
        for(int i=0; i<k; i++){
            ll a =sumla[C].at(i)+s[N-1 - (i+1)*C];
            sumla[C].push_back(a);
        }
    }

    ll ans=0;
    for(int C=1; C<N; C++){
        int k=(N-1)/C;
        for(int i=1; i<=k; i++){
            int A=N-1-i*C;
            if(A<=C) continue;
            if(A%C==0 && A/C <=i ) continue;
            ans = max(ans,sumst[C].at(i)+sumla[C].at(i));
//            cout << C << " " << i << endl;
        }
    }
    cout << ans << endl;
}