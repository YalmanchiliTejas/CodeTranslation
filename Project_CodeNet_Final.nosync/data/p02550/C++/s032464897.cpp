#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(a) a.begin(), a.end()
#define P pair<int, int>
#define F first
#define S second
#define MOD 998244353
int iso_lower(vector<int> V, int x) {
    //ソートされたVの中から、V[i]>=xとなる最小のiを返す.存在しなければVの要素数を返す
    int s = V.size();
    //V.push_back(INF);
    int l = -1;
    int r = s;  //rが常にtrue
    while(r - l > 1) {
        int mid = (l + r) / 2;
        if(V[mid] < x)
            l = mid;
        else
            r = mid;
    }
    return r;
}
signed main(){
    int N,X,M;cin>>N>>X>>M;
    vector<int>Ru;
    Ru.push_back(-1);
    vector<int>Ju(M,-1);
    Ru.push_back(X);Ju[X]=1;
    int now=1,a=X;
    int fi,en;
    while(true){
        now++;
        a=(a*a)%M;
        Ru.push_back(a);
        if(now==N){
            int ans=0;
            for(int i=1;i<=N;i++){
                ans+=Ru[i];
            }
            cout<<ans<<endl;
            return 0;
        }
        if(Ju[a]==-1){
            Ju[a]=now;
            continue;
        }
        else{
            fi=Ju[a];
            en=now;
            break;
        }
    }
    int ans=0;
   // for(auto x:Ru)cout<<x<<' ';
    //cout<<endl;
    rep(i,fi-1)ans+=Ru[i+1];
    int roop=0;
    for(int i=fi;i<en;i++)roop+=Ru[i];
    int length=en-fi;
    int K=(N-fi+1)/length;
    ans+=roop*K;
    for(int i=1;i<=N-fi-length*K+1;i++){
        ans+=Ru[i+fi-1];
    }
    cout<<ans<<endl;
}
