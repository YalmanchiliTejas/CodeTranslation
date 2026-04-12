#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=1005;
int num[maxn];
int dp[maxn];

int main()
{
    int n;
    while(cin>>n){
        for(int i=0;i<n;i++){
            cin>>num[i];
        }
        int temp = 0, ans = 0;
        for(int i=0;i<n;i++){
            if(num[i] >= temp) {
                ans++;
                temp = num[i];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
