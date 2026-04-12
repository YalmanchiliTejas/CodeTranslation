#include <bits/stdc++.h>
    
#define int long long
    
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define FORR(i,m,n) for(int i=m;i>=n;i--)
#define pb(x) push_back(x) 
#define SORT(x) sort((x).begin(),(x).end())
#define INF 99999999999
    
using namespace std;
    
int dy[4]={1, -1, 0, 0};
int dx[4]={0, 0, 1, -1};

int32_t main(){
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int ans_1, ans_2=ans_1=0;
    if(a+b>c*2){
        REP(i, x){
            ans_1+=c*2;
        }
        if(y-x>0){
            REP(i, y-x){
                ans_1+=b;
            }
        }
        REP(i, y){
            ans_2+=c*2;
        }
        if(x-y>0){
            REP(i, x-y){
                ans_2+=a;
            }
        }
        cout << min(ans_1, ans_2) << endl;
    }
    else{
        int ans=0;
        REP(i, x) ans+=a;
        REP(i, y) ans+=b;
        cout << ans << endl;
    }
}