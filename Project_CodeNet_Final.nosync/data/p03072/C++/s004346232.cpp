#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0;i < n;i++)
#define rev(i, n) for(int i = n;i >= 0;i--)
#define Rep(i, m, n) for(int i = m;i < n;i++)
#define repeatrev(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define ll long long
#define pb(a) push_back(a)
#define INF 999999999
#define itn int

using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;
typedef priority_queue<int> Pr;

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int h[n];
    int g = 1;

    rep(i, n) cin >> h[i];
    for(int i = 1; i < n; i ++){
        int jj = 0;
        for(int j = 0; j < i; j ++){
            if(h[i] >= h[j]) jj++;
        }
        if(jj == i ) g ++;
       // if(h[i + 1] >= h[i]) g ++;
    }
   /* int max1 = h[0];
    rep(i, n){
        if(h[i] >= max1){
            g ++;
            max1 = h[i];
        }
    }*/
    cout << g << endl;
}