#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define N 100000
#define INF 100000000
typedef long long ll;
#define ALL(v) (v).begin(),(v).end()
#define SZ(x) int(x.size())
#define IN(a) cin>>(a)
#define OUT(a) cout<<(a)<<endl
typedef pair<int,int> P;
const int MAX = 100005;
const int MOD = 1000000007;
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    REP(i,n){
        cin>>a[i];
    }
    int m=a[0];
    int ans=0;
    REP(i,n){
        if(m<=a[i]){
            ans++;
            m=a[i];
        }
    }
    OUT(ans);
    return 0;
}