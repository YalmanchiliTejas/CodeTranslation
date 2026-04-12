#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<vector<int> > Graph;

int main(){
    int x,y,z;
    cin >> x >> y >> z;
    int haba=x-z;
    int ans=0;
    ans += haba/(y+z);
    cout << ans << endl;
    
    return 0;
}