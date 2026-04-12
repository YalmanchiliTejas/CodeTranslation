#include "bits/stdc++.h"
#define REP(i, m, n) for(long long i = m; i < n; ++i)
#define CO(n) cout << n << endl
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int N,M;
int ans=0;
int a[60],b[60];
int perm[8];

int main()
{
    ios::sync_with_stdio(false);
    cin >> N >> M;
    REP(i,0,M) cin >> a[i] >> b[i];
    REP(i,0,M){
        a[M+i]=b[i]; b[M+i]=a[i];
    }
    REP(i,0,N) perm[i]=i+1;
    do {
        bool flag, flag2;
        REP(i,0,N-1){
            flag = false;
            flag2 = true;
            int s=perm[i]; int g=perm[i+1];
            REP(j,0,2*M){
                if (s == a[j] && g == b[j]){
                    flag = true;
                    break;
                }
            }
            if (!flag){
                flag2 = false;
                break;
            }
        }
        if (flag2) ++ans;
    } while(next_permutation(perm+1, perm+N));
    CO(ans);
    return 0;
}