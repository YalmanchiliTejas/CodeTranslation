#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long
using namespace std;
vector<int> to[9];
int main(){
    int n,m;
    cin >> n >> m;
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    vector<int> v;
    rep(j,n-1){
        v.push_back(j+1);
    }
    int cnt = 0;
    do{
        int a = 0;
        bool flag = true;
        rep(i,n-1){
            int b=v[i];
            for(auto& p: to[a]){
                if(p == b){
                    flag = true;
                    a = b;
                }else{
                    flag = false;
                }
                if(flag) break;       
            }
            if(!flag) break;
        }
        if(flag){
            cnt++;
        }
    }while(next_permutation(v.begin(),v.end()));
    cout << cnt << endl;
}