#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int a[3000];
long int dp[3000][3001];
bool checked[3000][3001];

long int get(int l, int r, int turn){

    if(l == r){
        return 0;
    }

    if(checked[l][r]){
        return dp[l][r];
    }
    else{
        long int temp = 0;

        if(turn == 0){
            temp = max(get(l + 1, r, 1) + a[l], get(l, r - 1, 1) + a[r - 1]);
        }
        else{
            temp = min(get(l + 1, r, 0) - a[l], get(l, r - 1, 0) - a[r - 1]);
        }
        dp[l][r] = temp;
        checked[l][r] = true;
        return temp;
    }
}

int main(){

    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &a[i]);
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j <= N; j++){
            checked[i][j] = false;
        }
    }

    long int ans = get(0, N, 0);
    printf("%ld\n", ans);

    return 0;
}