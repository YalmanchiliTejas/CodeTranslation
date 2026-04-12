//c++ テンプレ
#include<bits/stdc++.h>
using namespace std;

typedef long long llint;
typedef long double ld;

#define inf 1e18
#define mod 1000000007
priority_queue<llint,vector<llint>,greater<llint> > que;
priority_queue<llint> Que;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int H,W;
vector<string>A;
void solve(){
    cin >> H >> W;
    A.resize(H);
    for(int i=0;i<H;i++){
        cin >> A[i];
    }
    int cnt=0;
    for(int h=0;h<H;h++){
        for(int w=0;w<W;w++){
            if(A[h][w]=='#')cnt++;
        }
    }
    if(cnt==H+W-1)cout << "Possible" << endl;
    else cout << "Impossible" << endl;

    
 
}

int main(){
  solve();
  return 0;
}
