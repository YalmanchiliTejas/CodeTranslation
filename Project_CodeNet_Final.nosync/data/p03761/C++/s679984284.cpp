#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    int N;
    cin >> N;
    vector<string> S(N);
    rep(i,N) cin >> S[i];
    map<char,int> M;
    for(int i=0;i<N;i++){
        map<char,int> m;
        for(int j=0;j<S[i].size();j++){
            m[S[i][j]]++;
            if(i==0){
                M[S[i][j]]++;
            }
        }
        for(char k='a';k<='z';k++){
            M[k]=min(M[k],m[k]);
        }
    }
    string ans = "";
    for(char k='a';k<='z';k++){
        int num = M[k];
        rep(i,num){
            ans+=k;
        }
    }
    cout << ans << endl;
    return 0;
}