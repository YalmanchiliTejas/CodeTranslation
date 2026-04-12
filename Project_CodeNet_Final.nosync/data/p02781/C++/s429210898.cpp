#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;
#define pa pair<int, int> 
#define pal pair<long long, long long>
#define pad pair<double, double>
#define pb push_back
#define mp make_pair
#define VIN(v) for(int64_t i=0;i<(v).size();i++){cin >> (v).at(i);}

typedef vector<bool> bvec;
typedef vector<int> ivec;
typedef vector<long long> lvec;
typedef vector<double> dvec;
typedef vector<pa> pvec;

typedef vector< vector<bool> > bmat;
typedef vector< vector<int> > imat;
typedef vector<string> svec;
typedef vector< vector<string> > smat;

ll C(int n, int r) {
    if(r > n - r) r = n - r; 
    ll ans = 1;
    int i;

    for(i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}

int dp[101][4][2];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    string n;
    int k;
    cin >> n >> k;
    int d =  n.size();
    for(int i=0; i<k+1; i++){
        if (i==0){
            dp[0][i][1] = 1;
            dp[0][i][0] = 0;
        }
        else if(i==1){
            dp[0][i][0] = 1;
            dp[0][i][1] = (int)(n[0]-'0')-1;
        }
        else {
            dp[0][i][0] = 0;
            dp[0][i][1] = 0;
        }


    }
    for(int i=1; i<d; i++){
        int x = int(n[i] - '0')-1;
        for(int j=0; j<k+1; j++){
            if(j>=1){
                dp[i][j][1] = dp[i-1][j][1] + 9*(dp[i-1][j-1][1]) + fmax(x, 0)*dp[i-1][j-1][0];
                if(x==-1) {
                    dp[i][j][0] = dp[i-1][j][0];
                }
                else {
                    dp[i][j][0] = dp[i-1][j-1][0];
                    dp[i][j][1] += dp[i-1][j][0];
                }

            }
            else {
                dp[i][j][0] = 0;
                dp[i][j][1] = 1;
            }
        }
    }
    cout << dp[d-1][k][0] + dp[d-1][k][1] << endl;
}
