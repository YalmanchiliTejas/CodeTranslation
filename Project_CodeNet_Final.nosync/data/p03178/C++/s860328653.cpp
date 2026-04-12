#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int main(){
    string n;
    int d;
    cin >> n;
    cin >> d;
    long long int ans[n.size()+1][d];
    memset(ans, 0, sizeof(ans));
    for(int i=0;i<10; i++){
        ans[1][i%d]++;
    }
    for(int i=2; i<=n.size(); i++){
        for(int j=0; j<d; j++){
            for(int k=0; k<10; k++){
                ans[i][(j+k)%d] = (ans[i][(j+k)%d] + ans[i-1][j%d])%mod;
            }
        }
    }
    long long int res = 0, x = 0, index = 0;
    long long int counter = 0;
    for(int i=n.size(); i>1; i--,index++){
        for(int j=0; j<n[index]-'0'; j++){
            counter = (counter + ans[i-1][(d-(res + j)%d)%d])%mod;
        }
        res = (res + n[index] -'0')%d;
    }
    for(int i=0;i<=n[index]-'0'; i++){
        if((res+i)%d == 0)
            counter = (counter+1)%mod;
    }
    cout << ((counter - 1)%mod+mod)%mod;
}
