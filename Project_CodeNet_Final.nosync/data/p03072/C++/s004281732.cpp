#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<vector>
#include<set>
using namespace std;
typedef long long ll;
typedef long long int llint;
typedef pair<ll, ll> pa;
#define MM 1e9
#define MOD MM+7
#define MAX 101000
#define MAP 110
#define initial_value -1
#define Pair pair<int,int>
#define chmax(a,b) (a<b ? a=b:0)
#define chmin(a,b) (a>b ? a=b:0)
#define INF (1 << 29) //536870912
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
int main(){
    int n; cin >> n;
    int h[22];
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }
    int mx = h[0];
    int ans = 1;
    for(int i = 1; i < n; i++){
        if(mx <= h[i]){
            ans++;
            mx = h[i];
        }
    }
    cout << ans << endl;
}