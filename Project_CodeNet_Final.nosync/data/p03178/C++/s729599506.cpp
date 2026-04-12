
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;
int k, mod = 1e9+7;
int newdp[105][5], olddp[105][5];

int main(){
    cin >> s >> k;
    
    olddp[0][1] = 1;
    for(int i = 0; i < s.size(); i++){
        for(int sum = 0; sum < k; sum++){
            for(int j = 0; j <= 9; j++)
                newdp[(sum+j)%k][0] = (newdp[(sum+j)%k][0] + olddp[sum][0])%mod;
            for(int j = 0; j < s[i]-'0'; j++)
                newdp[(sum+j)%k][0] = (newdp[(sum+j)%k][0] + olddp[sum][1])%mod;
                
            int c = s[i]-'0';
            newdp[(sum+c)%k][1] = (newdp[(sum+c)%k][1] + olddp[sum][1])%mod;
        }
        for(int sum = 0; sum < k; sum++)
            for(int flag = 0; flag < 2; flag++){
                olddp[sum][flag] = newdp[sum][flag];
                newdp[sum][flag] = 0;
            }
    }
    int res = (olddp[0][0] + olddp[0][1] - 1 + mod)%mod;
    cout << res << endl;
    return 0;
}