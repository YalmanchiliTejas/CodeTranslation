#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);    cin.tie(NULL);  cout.tie(NULL);
    int n;  cin >> n;   vector<long long int> vec(n);
    vector< vector<long long int> > dp(n, vector<long long int>(n));
    for(int i=0;n>i;i++){
        cin >> vec[i];
    }
    for(int left=n-1;left>=0;left--){
        for(int right=left;right<n;right++){
            if(right==left){
                dp[left][right]=vec[right]; continue;
            }
            dp[left][right]=max(vec[left]-dp[left+1][right], vec[right]-dp[left][right-1]);
        }
    }
    cout << dp[0][n-1];
}