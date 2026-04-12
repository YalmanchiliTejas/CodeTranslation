#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9+7;
typedef pair<int, int> ii;

int h[105];

long long memo[5][105][105];

long long pow2(long long b){
    if(b <= 29){
        return 1<<b;
    }else{
        long long temp = pow2(b>>1);
        if(b&1){
            return ((temp*temp)<<1)%MOD;
        }else{
            return temp*temp%MOD;
        }
    }
}

long long dp(int mode, int i, int j, int offset = 0){
    //if(i != 0 || j != 8){return 1;}
    if(memo[mode][i][j] != -1){
        return memo[mode][i][j];
    }

    int x = MOD;
    for(int k = i; k <= j; k ++){
        x = min(x, h[k]);
    }

    int w = 0;
    for(int k = i; k <= j; k ++){
        w += (h[k] == x);
    }

    vector<ii> startEnd;
    int s = i;
    for(int k = i; k <= j+1; k ++){
        if(k == j+1 || h[k] == x){
            // stop here
            int e = k;
            if(s == e){
                s = k+1;
                continue;
            }
            startEnd.push_back(ii(s, e-1));
            s = k+1;
        }
    }

    if(w == 0){w = j-i+1;} // edge case when all the heights are the same

    /*printf("dp(%d, %d, %d) offset=%d x=%d w=%d\n", mode, i, j, offset, x, w);
    for(ii se: startEnd){
        printf("ii(%d, %d)\n", se.first, se.second);
    }*/

    if(mode == 1){
        long long ans1 = pow2(x-offset);

        for(ii se: startEnd){
            int s, e;
            tie(s, e) = se;
            ans1 = ans1*dp(1, s, e, x)%MOD;
        }

        return memo[mode][i][j] = ans1%MOD;
    }else if(mode == 3){
        long long ans1 = (pow2(x-offset)+MOD-2)%MOD;
        long long ans3 = pow2(w);

        for(ii se: startEnd){
            int s, e;
            tie(s, e) = se;
            ans1 = ans1*dp(1, s, e, x)%MOD;
            ans3 = ans3*(dp(1, s, e, x)+dp(3, s, e, x))%MOD;
        }

        return memo[mode][i][j] = (ans1+ans3)%MOD;
    }
}

int main(){
    int N;
    scanf("%d", &N);

    for(int i = 0; i < N; i ++){
        scanf("%d", &h[i]);
    }

    memset(memo, -1, sizeof(memo));
    printf("%lld", dp(3, 0, N-1));
    return 0;
}
