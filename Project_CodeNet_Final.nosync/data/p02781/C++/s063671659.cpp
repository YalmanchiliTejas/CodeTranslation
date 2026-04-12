#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>

using namespace std;

int main()
{
    string N;
    int n,K,l;
    cin >> N;
    cin >> K;
    l = N.size();
    
    int dp[l+1][K+1][2]={0};
    
    
    for(int i=0;i<l+1;i++){
        for(int j=0; j<K+1; j++){
            for(int k=0;k<2;k++){
                dp[i][j][k]=0;
            }
        }
    }

    dp[0][0][0] = 1;

    
    for(int i=0;i<l;i++){
        for(int j=0; j<K+1; j++){
            for(int k=0;k<2;k++){
                n = N[i] - '0';
                for(int d=0;d<10;d++){
                    int next_i = i+1;
                    int next_j = j;
                    int next_k = k;
                    if(d != 0){
                        next_j += 1;
                    }
                    if(next_j > K)
                        continue;
                    if(k==0){
                        if(d > n)
                            continue;
                        if(d < n)
                            next_k = 1;
                    }
                    dp[next_i][next_j][next_k] += dp[i][j][k];
                }
            }
        }
    }
    
    cout << dp[l][K][0] + dp[l][K][1];
    return 0;
}
/*
    int m,n,k,cand;
    cin >> m >> n >> k;

    int a[m+1] = {0};
    a[0] = n;

    for(int i=0;i<k;i++){
        cin >> cand;
        for(int j=0; j<m+1; j++){
            if(a[j]>0){
                a[j]--;
                a[cand]++;
            }
        }
    }
    
    int maxi=0;
    for(int i=1;i<m+1;i++){
        if(a[i]>maxi) 
            maxi = a[i];
    }

    for(int i=1;i<m+1;i++){
        if(a[i]==maxi) 
            cout << i << endl;
    }


    for(int i=1;i<m+1;i++){
        cout << a[i] << endl;
    }
*/
 

