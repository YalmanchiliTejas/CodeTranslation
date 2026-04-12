#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define p(s) cout<<(s)<<endl
#define REP(i,n,N) for(int i=n;i<N;i++)
#define RREP(i,n,N) for(int i=N-1;i>=n;i--)
#define CK(n,a,b) ((a)<=(n)&&(n)<(b))
#define F first
#define S second
typedef long long ll;
using namespace std;
const ll inf = 1e18;

int N;
int x[200010];
int y[200010];
int main(){
    cin>>N;
    REP(i,0,N){
        cin>>x[i];
        y[i] = x[i];
    }
    sort(y,y+N);
    int a=y[N/2-1], b = y[N/2];
    REP(i,0,N){
        if(x[i]>=b){
            p(a);
        }else{
            p(b);
        }
    }
    return 0;
}
