#include<bits/stdc++.h>
#define LL long long
#define REP(i, n) for(int i=0;i<(n);++i)
#define REPA(i, n) for(int i=1;i<(n);++i)
#define lp(i, n) for(int i=-;i<(n);++i)
#define PII pair<int, int>
#define PLL pair<long long, long long>
#define MOD ((int)1e9 + 7)
#define INF ((int)1e9)
#define DEKAI ((int)1e9+7)
#define ALL(x) (x).begin(), (x).end()
#define BIT(x) (1<<(x))
#define foreach(i, n) for(auto &i:(n))
using namespace std;

int main(){
    while(true)
    {
        int n, l, r; cin>>n>>l>>r;
        if(n+l+r==0) break;

        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        int ans=0;
        for(int x=l;x<=r;x++){
            bool flag=false;
            for(int i=0;i<n;i++){
                if(x%a[i]==0){
                    flag=true;    
                    if(i%2==0){
                        ans++;
                    }
                    break;
                }
            }
            if(!flag and n%2==0){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
}

