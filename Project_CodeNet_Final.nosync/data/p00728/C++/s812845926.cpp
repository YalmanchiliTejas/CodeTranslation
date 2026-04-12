#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
#define INF 999999999
using namespace std;
typedef pair<int, int> P;
typedef pair<llong, llong> LP;
typedef pair<int, P> PP;
typedef pair<llong, LP> LPP;

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

int main(){
    int n;
    scanf("%d",&n);
    while(n!=0){
        vector<int> s;
        int sum=0;
        REPR(i,n-1){
            int sn;
            scanf("%d",&sn);
            s.push_back(sn);
        }
        sort(s.begin(),s.end());
        FOR(i,1,s.size()-1){
            sum=sum+s[i];
        }
        int ave=sum/(n-2);
        printf("%d\n",ave);
        scanf("%d",&n);
    }
    return 0;
}
