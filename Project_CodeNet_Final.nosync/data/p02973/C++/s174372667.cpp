#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define N 105
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
    REP(i,n)IN(a[i]);
    vector<int>b(1);
    b[0]=a[n-1];
    for(int i=n-2;i>=0;i--){
        int x=upper_bound(ALL(b),a[i])-b.begin();
        if(x==SZ(b)){
            b.push_back(a[i]);
        }else{
            b[x]=a[i];
        }
    }
    OUT(SZ(b));
    return 0;
}