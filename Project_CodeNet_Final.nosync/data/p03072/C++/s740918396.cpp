#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define REP(i,s,l) for(lli i=s;i<l;i++)
#define DEBUG 0
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    int n, cnt=1;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++) cin >> a[i];
    int h = a[0];
    for(int i=1; i<n; i++){
        if(h<=a[i]){
            cnt++;
            h = a[i];
        }
    }
    cout << cnt << endl;
    return 0;
}