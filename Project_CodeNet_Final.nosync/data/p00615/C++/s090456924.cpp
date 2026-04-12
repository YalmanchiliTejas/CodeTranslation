#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

int MOD=1e9+7;
ll INF=1e18;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

int main(){
    while(1){
        int n, m; cin>>n>>m;
        if(n==0 && m==0) return 0;
        vector<ll> a(n+m);
        for(int i=0; i<n+m; i++) cin>>a[i];
        sort(a.begin(), a.end());
        ll gap=a[0];
        for(int i=0; i<n+m-1; i++){
            gap=max(gap, a[i+1]-a[i]);
        }
        cout << gap << endl;
    }
}
