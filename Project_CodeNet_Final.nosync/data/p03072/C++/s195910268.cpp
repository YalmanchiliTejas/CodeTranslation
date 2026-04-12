#include<cstdio>
#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#include<queue>
#include<functional>
#include<map>
#include<set>
#include<cstring>
#include<string>
#include<stack>
#include<math.h>
#include<stdlib.h>
using namespace std;
//#define int long long
typedef pair<int, int> pii;
typedef pair<int, char> pic;
typedef priority_queue<pii, vector<pii>, greater<pii> > RPQ;
#define mk make_pair
#define INF (1 << 30)
#define INFL (1ll << 60ll)
#define mod 1000000007

int N, K;
string s;
int ans1, ans2;

signed main(){
    cin >> N;
    int mx = 0;
    for(int i = 0; i < N; i++){
        int h;
        cin >> h;
        if(mx <= h)ans1++;
        mx = max(mx, h);
    }
    cout << ans1 << endl;


    return 0;
}

/*

*/