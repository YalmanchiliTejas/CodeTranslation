#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define se second
#define pi 2*acos(0)
#define PI 3.14159265358979323846264338

typedef long long ll;
typedef pair < int , int > pii;
typedef pair < ll , ll > pll;
const int N = 100010;

inline int in() {int x; scanf("%d",&x); return x;}
inline ll lin() {ll x; scanf("%lld",&x); return x;}

int fx[]={1,-1,0,0};
int fy[]={0,0,-1,1};

int inp[N + N];
int ans[N + N];

int main(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> inp[i];
    }
    for(int i = n / 2 + 1, j = 1; i <= n; i++, j += 2){
        ans[i] = inp[j];
    }
    for(int i = n / 2, j = 2; i >= 1; i--, j += 2){
        ans[i] = inp[j];
    }
    if(n & 1){
        int lo = 1, hi = n;
        while(lo < hi){
            swap(ans[lo], ans[hi]);
            lo++; hi--;
        }
    }
    for(int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }
}
