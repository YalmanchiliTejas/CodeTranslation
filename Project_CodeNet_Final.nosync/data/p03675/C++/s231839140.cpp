#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
typedef pair<pii, int> piipi;
typedef pair<pii, pii> piipii;

#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define eb emplace_back

int a[200005];
deque<int> dq;
int main(){
    int n, b = 0;
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        scanf("%d", &a[i]);
        if(b == 0) dq.push_back(a[i]);
        else dq.push_front(a[i]);
        b ^= 1;
    }   
    if(b == 0){
        for(int i=0;i<sz(dq);i++) printf("%d ", dq[i]);
    }
    else{
        for(int i=sz(dq)-1;i>=0;i--) printf("%d ", dq[i]);  
    }
}