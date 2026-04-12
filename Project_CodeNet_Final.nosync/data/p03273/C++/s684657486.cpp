#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
constexpr double EPS = 1e-12;
constexpr int INF = numeric_limits<int>::max()/2;
constexpr int MOD = 1e9+7;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int h,w;cin>>h>>w;
    vector<string> s(h);
    vector<int> yoko(h,0),tate(w,0);
    for(int i=0;i<h;i++){
        cin>>s[i];
        for(int j=0;j<w;j++){
            if(s[i][j]=='#'){
                yoko[i]++;
                tate[j]++;
            }
        }
    }
    for(int i=0;i<h;i++){
        if(yoko[i]==0) continue;
        for(int j=0;j<w;j++){
            if(tate[j]==0) continue;
            cout<<s[i][j];
        }
        cout<<endl;
    }
}
