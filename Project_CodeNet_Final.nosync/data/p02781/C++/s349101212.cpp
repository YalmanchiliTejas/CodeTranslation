#include <bits/stdc++.h> 
using namespace std;
#define rep(i, N) for(int i=0; i<N; i++)
typedef long long ll;
#define dump(x) cerr<<#x<<"="<<x<<endl

ll dp[110][110][2];

int main() {
    string n;
    int K;

    cin >> n >> K;
    vector<int> N;

    for(auto a: n){
        N.push_back(a-'0');
    }
    int l = n.size();

    dp[0][0][0] = 1;
    for(int i=0; i<l; i++){
        for(int j=0; j<=K; j++){
            for(int k=0; k<2; k++){
                for(int x=0; x<10; x++){    
                    int ni=i+1, nj=j, nk=k;
                    if(k==0){
                        if(x>N.at(i)) continue;
                        else if(x<N.at(i)) nk=1;
                    }
                    if(x!=0) nj++;
                    dp[ni][nj][nk] += dp[i][j][k];
                }
            }
        }
    }

    std::cout << dp[l][K][0] + dp[l][K][1] << endl;


}