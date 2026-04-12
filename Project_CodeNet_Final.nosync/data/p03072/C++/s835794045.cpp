#include <bits/stdc++.h>
#include <cstdlib>
#define ll long long
#define FOR(i,x,y) for(ll i=(ll)x; i<(ll)y; ++i)
#define MX 100010
using namespace std;

int N;
vector<int> H;
int ans;

int main(){
        cin >> N;
        H.resize(N);
        FOR(i,0,N){
                cin >> H[i];
        }
        FOR(i,0,N){
//                cout << "i=" << i << endl;
                int j;
                for(j=0;j<i;j++){
                        if(H[j]>H[i]) break;
                }
//                cout << j << "," << i << endl;
                if(j==i){
                        ans++;
                }
        }

        cout << ans << endl;

        return 0;
}
