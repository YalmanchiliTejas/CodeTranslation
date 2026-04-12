#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <deque>
#include <iomanip>
#include <cstdio>
#include <stack>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007
#define mod 1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}
int n;
ll a[3010];
ll dp[3010][3010];
bool flag[3010][3010][2];

ll saiki(int p,int q,int s){
    if(p==q){
        return a[p];
    }
    if(flag[p][q][s]){
        return dp[p][q];
    }
    flag[p][q][s] = 1;
    
    if(s==1){
        ll tmp = a[q] - saiki(p,q-1,1-s);
        ll tmp2 = a[p] - saiki(p+1,q,1-s);
        return dp[p][q] = max(tmp,tmp2);
    }else{
        ll tmp = a[q] - saiki(p,q-1,1-s);
        ll tmp2 = a[p] - saiki(p+1,q,1-s);
        return dp[p][q] = max(tmp,tmp2);
    }
}

int main(){
    cin >> n;
    rep(i,n){
        cin >> a[i];
    }
    cout << saiki(0,n-1,1) << endl;
    return 0;
}