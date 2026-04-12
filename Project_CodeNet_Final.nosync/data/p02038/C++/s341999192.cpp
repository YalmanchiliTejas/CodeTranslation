#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define rep1(i,n) for(int i=1; i<n; i++)
#define all(v) (v).begin(),(v).end()
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
using namespace std;
typedef long long LL;
typedef pair<int, int> P;

int main(){
    int n;
    cin >> n;
    char now, next;
    cin >> now;
    rep(i, n-1){
        cin >> next;
        if(now == 'T' && next == 'F') now = 'F';
        else now = 'T';
    }
    cout << now << endl;
}

