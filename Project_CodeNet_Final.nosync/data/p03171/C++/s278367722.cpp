#include<iostream>
#include<fstream>
#include<math.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<chrono>
#include<math.h>

#define FIO ios_base::sync_with_stdio(0);  cin.tie(0);
#define PI 3.14159265358979323846
#define mod 998244353
#define ll long long
#define vll vector<long long>  
#define all(c) c.begin(), c.end()
// Used to traverse in any STL container with iterators
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
// Find whether element is present in given container or not
#define present(container, element) (container.find(element) != container.end())
// Finds whether element in present container is present in vector or not
#define cpresent(container, element) (find(all(container),element) != container.end())

using namespace std;
using namespace std::chrono; 


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
    FIO

    int n;
    cin>>n;
    ll arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    
    long dp[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j)dp[i][j] = arr[i];
            else dp[i][j] = 0;
        }
    }
    int j;
    for(int len=2;len<=n;len++){
        for(int i=0;i<=n-len;i++){
            j = i+len-1;
            if(len%2==0)dp[i][j] = min(dp[i+1][j] - arr[i], dp[i][j-1] - arr[j]);
            else dp[i][j] = max(dp[i+1][j] + arr[i], dp[i][j-1] + arr[j]);
        }
    }
    if(n%2 == 0)cout<<(-1)*dp[0][n-1]<<endl;
    else cout<<dp[0][n-1]<<endl;
    
    return 0;
}