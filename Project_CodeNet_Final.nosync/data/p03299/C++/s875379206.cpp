#include <iostream>
#include<bits/stdc++.h>

typedef long long LL;

using namespace std;
LL M = 1000000007;
LL pow(LL a,LL b,LL m){
    if(b==0){
        return 1;
    }
    else if (b%2 ==0 ){
        LL y = pow(a,b/2,m);
        return (y*y)%m;
    }
    else{
        return (a*pow(a,b-1,m))%m;
    }

}


int main()
{
    LL N;
    cin>>N;
    LL arr[N], check[N], sorted[N];
    for(int i=0; i<N; i++){
        cin>>arr[i];
        sorted[i] = arr[i];
    }
    sort(sorted, sorted +N);
    for(int i=0; i<N; i++){
        LL counter = 0;
        for(int j=0; j<N; j++){
            if(j<i && arr[j] <= arr[i])
                counter++;
            if(j>i && arr[j] < arr[i])
                counter++;
        }
        check[i] = counter;
    }

    LL dp[N][N + 1];
    for(int i=0; i<N; i++){
        for(int j=0; j<N + 1; j++){
            dp[i][j] = 0;
        }
    }


    for(int i=1; i<=check[0] + 1; i++){
        dp[0][i] = (pow(2, sorted[check[0]] - sorted[i - 1], M)*2)%M;
    }
    dp[0][0] = (pow(2, sorted[check[0]], M)%M);


    for(int i=1; i<N; i++){
       if( check[i] > check[i-1]){
            for(int j=0; j <= check[i -1] + 1; j++){
                dp[i][j] += (dp[i-1][j]* pow(2, sorted[check[i]] - sorted[check[i-1]], M))%M;
                dp[i][j] += (dp[i-1][check[i-1] + 1] * pow(2, sorted[check[i]] - sorted[check[i-1]], M))%M;
                dp[i][j] = dp[i][j]%M;
            }
            for(int j = check[i-1] + 2; j <= check[i] + 1; j++){
                dp[i][j] += (dp[i-1][check[i-1] + 1] * 2 * pow(2, sorted[check[i]] - sorted[j-1], M))%M;
                dp[i][j] = dp[i][j]%M;
            }

       }
       else{
            for(int j=0; j<=check[i] + 1; j++){
                dp[i][j] += dp[i-1][j];
                dp[i][j] += dp[i-1][check[i] + 1];
                dp[i][j] = dp[i][j]%M;
            }
       }
    }
    cout<<dp[N-1][0]<<endl;
    return 0;
}
