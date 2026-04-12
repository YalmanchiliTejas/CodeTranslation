#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define fi first
#define se second
#define mp make_pair
#define itrfor(itr,A) for(auto itr = A.begin(); itr !=A.end();itr++)
template <class T> using reversed_priority_queue = priority_queue<T, vector<T>, greater<T> >;
typedef long long llong;
char moji[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
char moji2[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char moji3[10]={'0','1','2','3','4','5','6','7','8','9'};
#define Sort(a) sort(a.begin(),a.end());
#define Reverse(a) reverse(a.begin(),a.end());
#define print(a) cout << a << endl;
#define MOD llong(1e9+7)
#define MAX int(2 * 1e5 +5)
#define debug(x)  cout << #x << " = " << (x) << endl;
#define pi acos(-1.0)
#define int llong
#define INF llong(1e17)
template<class T> bool chmax(T &a,  T b) {if(a<b){a=b; return 1;} return 0;}
template<class T> bool chmin(T &a,  T b) {if(a>b){a=b; return 1;} return 0;}
bool Add(int &a,int b){a = (a + b) % MOD;}
void myprint(int* A,int A_num){
   REP(i,A_num) cout << A[i] << " ";
   cout << endl;
}

signed main(){
    int n;
    cin >> n;
    int A[n];
    int r = 0;
    bool flag = false;
    REP(i,n){
        cin >> A[i];
        r += A[i];
        if(A[i] >= n) flag = true;
    }
    if(flag == false){
        cout << 0 << endl;
        return 0;
    }
    int l = 0;
    while(l + 1 < r){
        int mid = (l + r) / 2;
        int su = 0;
        REP(i,n){
            if(A[i] - n + 1 + mid <= 0) continue;
            su += (A[i] - n + 1 + mid) / (n+1);
            if( (A[i] - n + 1 + mid) % (n+1) !=0){
                su += 1;
            } 
        }
        if(su > mid) l = mid;
        else r = mid;
    }
    int ans = r;
    REP(i,100000){
        int mid = ( r - i);
        int su = 0;
        REP(i,n){
            if(A[i] - n + 1 + mid <= 0) continue;
            su += (A[i] - n + 1 + mid) / (n+1);
            if( (A[i] - n + 1 + mid) % (n+1) !=0){
                su += 1;
            } 
        }
        if(su > mid) l = mid;
        else ans = mid;
    }
    cout << ans<< endl;
}