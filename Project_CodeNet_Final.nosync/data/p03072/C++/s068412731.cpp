#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repb(i, n) for (int i = (int)n; i >= 0; i--)
#define reps(i, m, n) for (int i = (int)m; i < (int)n; i++)
#define repsb(i, m, n) for (int i = (int)m; i >= (int)n; i--)
#define SORT(v, n) sort(v, v + n);
#define VSORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
#define INF 999999999999999999
int dy[] = {0, 0, 1, -1, 0};
int dx[] = {1, -1, 0, 0, 0};
using namespace std;
int main(int argc, char const *argv[])
{
    int n,ans=1;
    cin>>n;
    vector<int> h(n);
    rep(i,n)    cin>>h[i];
    rep(i,n){
        repb(j,i-1){
            if(h[i]<h[j])   break;
            if(j==0)    ans++;
        }
    }
    cout<<ans<<endl; 
    return 0;
}