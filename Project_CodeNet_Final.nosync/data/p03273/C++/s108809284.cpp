#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long int i=0;i<n;++i)
typedef long long int ll;

int main(){

    int h,w;
    cin >> h >> w;

    vector<string> a(h);

    rep(i,h) cin >> a[i];

    bool f=true;
    while(f){
        f=false;
        string row(a[0].size(),'.');

        rep(i,a.size()){
            if(a[i]==row){
                a.erase(a.begin()+i);
                f=true;
                i--;
            }
        }

        rep(i,a[0].size()){
            rep(j,a.size()){
                if('.'!=a[j][i]){
                    break;
                }
                if(j==a.size()-1){
                    
                    rep(k,a.size()){
                        a[k].erase(a[k].begin()+i);
                    }
                    f=true;
                    i--;
                }
            }
        }
    }

    rep(i,a.size()){
        cout << a[i] << endl;
    }

    return 0;
}