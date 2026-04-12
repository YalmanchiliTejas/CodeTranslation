#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD=1e9+7;
ll INF=1e18;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

int main(){
    int a, b, c; cin>>a>>b>>c;
    if(a % (b+c) >= c) cout << a / (b+c) << endl;
    else cout << (a / (b+c)) - 1 << endl;
}