#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n;
int arr[3001];
ll dp[3001][3001];

int main() {
    cin >> n;
    for (int i=0;i<n;i++) {cin >> arr[i];}

    for (int L=n-1;L>=0;L--) {
        for (int R=L;R<=n-1;R++) {
            if (L==R) {dp[L][R]=arr[L];}
            else {dp[L][R]=max(arr[L]-dp[L+1][R],arr[R]-dp[L][R-1]);}
        }
    }
    cout << dp[0][n-1] << endl;

}
