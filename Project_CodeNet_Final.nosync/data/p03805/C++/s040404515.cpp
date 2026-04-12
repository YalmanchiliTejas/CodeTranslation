#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;




int main(){
    int n;
    int m;
    cin >> n >> m;
    int ans=0;
    vector <vector <int>> h(n);
    int a,b;
    rep(i,m){
        cin >> a >> b;
        --a;
        --b;
        h[a].push_back(b);
        h[b].push_back(a);
    }

    vector <int> t(n,0);
    queue <int> ba;
    queue <vector <int>> tu;
    t[0]=1;
    ba.push(0);
    tu.push(t);
    int nu;
    int l;
    int ma=1;
    queue <int> maq;
    maq.push(ma);

    while(ba.size()!=0){
        nu=ba.front();
        ba.pop();
        t=tu.front();
        tu.pop();
        l=h[nu].size();
        ma=maq.front();
        maq.pop();
        //cout << nu << " " << ma << endl;
        if(ma==n){
            ++ans;
        }
        else{
        rep(j,l){
            if(t[h[nu][j]]==0){
                t[h[nu][j]]=1;
                ba.push(h[nu][j]);
                tu.push(t);
                t[h[nu][j]]=0;
                maq.push(ma+1);

            }
        }
        }
    }

    cout << ans << endl;
    


    

    return 0;
}