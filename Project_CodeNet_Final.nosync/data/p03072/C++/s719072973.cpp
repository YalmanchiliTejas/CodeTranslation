#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long int lli;
#define pb emplace_back
#define mp make_pair
#define pii pair<int,int>
#define INF 1000000000
#define fastio	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

int n;
int h[30];

int main(){
    fastio;
    cin>>n;
    for(int i = 1;i<=n;i++)
        cin>>h[i];

    int sum = 1;
    for(int i = 2;i<=n;i++){
        int cnt = 0;
        for(int j = i-1;j>=1;j--){
            if(h[i] >= h[j])
                cnt++;
        }
        if(cnt == i-1)
            sum++;
    }    
    
    cout<<sum<<endl;
    return 0;
}
