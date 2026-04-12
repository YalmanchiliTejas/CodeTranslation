#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
#define MOD 1'000'000'007
using namespace std;
typedef long long ll;
typedef long double ld;

int n;
string s[50];
int cnt[26], sum[26];

int main(){
    cin>>n;
    rep(i,n){
        cin>>s[i];
    }
    fill(sum,sum+26,1001001001);

    rep(i,n){
        fill(cnt,cnt+26,0);
        rep(j,(int)s[i].size()){
            cnt[(int)(s[i][j]-'a')]++;
        }
        rep(j,26){
            sum[j]=min(sum[j],cnt[j]);
        }
    }

    string ans;
    rep(i,26){
        if(sum[i]!=1001001001){
            rep(j,sum[i]){
                char c='a'+i;
                ans+=c;
            }
        }
    }

    cout<<ans<<endl;
}