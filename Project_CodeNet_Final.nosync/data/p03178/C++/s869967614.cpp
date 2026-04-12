#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pi;
typedef vector<int> vi;
#define ST first
#define ND second
#define PB push_back
#define DET(a,b,c) (LL(b.x-a.x)*LL((c.y-a.y))-LL((c.x-a.x))*LL((b.y-a.y)))

const int MOD = 1000*1000*1000+7;
string K;
int D,len;
int dp[101][2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>K>>D;
    len = K.size();
    dp[0][0] = 1;
    for(int pos=0; pos<len; pos++) {
        int tmp[101][2];
        for(int sum=0; sum<D; sum++) {
            for(bool smaller:{0,1}) {
                tmp[sum][smaller] = 0;
            }
        }
        for(int sum=0; sum<D; sum++) {
            for(int smaller=0; smaller<2; smaller++) {
                for(int digit=0; digit<10; digit++) {
                    if(!smaller&&(digit>K[pos]-'0')) break;
                    tmp[(sum+digit)%D][smaller||(digit<K[pos]-'0')]+=dp[sum][smaller];
                    tmp[(sum+digit)%D][smaller||(digit<K[pos]-'0')]%=MOD;
                }
            }
        }
        for(int sum=0; sum<D;sum++) {
            for(bool smaller:{0,1}) {
                dp[sum][smaller] = tmp[sum][smaller];
                //cout<<pos<<" "<<sum<<" "<<smaller<<" "<<dp[sum][smaller]<<"\n";
            }
        }
    }
    int ans = (dp[0][0]+dp[0][1])%MOD;
    ans = (ans-1+MOD)%MOD;
    cout<<ans;
}
