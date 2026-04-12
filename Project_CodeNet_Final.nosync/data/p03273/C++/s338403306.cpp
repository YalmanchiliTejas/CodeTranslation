#include <bits/stdc++.h>
#define all(vec) vec.begin(),vec.end()
#define mp make_pair
using namespace std;
using ll=long long;
using P=pair<int,int>;
const ll INF=1LL<<30;
const ll LINF=1LL<<61;
const double eps=1e-9;
const ll MOD=1e9+7;
int main(){
    int h,w;cin>>h>>w;
    char c[110][110];
    for(int i=0;i<h;i++){
        cin>>c[i];
    }
    vector<int> c1(h),c2(w);
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(c[i][j]=='#')c1[i]++;
        }
    }
    for(int j=0;j<w;j++){
        for(int i=0;i<h;i++){
            if(c[i][j]=='#')c2[j]++;
        }
    }
    for(int i=0;i<h;i++){
        if(c1[i]==0)continue;
        for(int j=0;j<w;j++){
            if(c2[j]==0)continue;
            cout<<c[i][j];
        }
        cout<<endl;
    }
}
