#include<bits/stdc++.h>
#define lli long long
#define rep0(i,j) for(int i=0; i<j; i++)
#define rep1(i,j) for(int i=1; i<=j; i++)
#define all(a) a.begin(), a.end()
using namespace std;

void dfs(lli ed, lli num, vector<map<lli,lli>>& vec){
    lli n=1;
    for(auto e: vec[num]){
        if(n == ed)n++;
        if(e.second != -1)continue;
        vec[num][e.first] = n;
        vec[e.first][num] = n;   
        dfs(n, e.first, vec);
        n++;
    }
}

int main(){
    lli n, x;
    cin >> n >> x;
    vector<lli> vec(n+1);
    lli size=1;
    vec[0] = 1;
    rep1(i,n){
        vec[i] = 2 * vec[i-1] + 1;
        size = 2*size + 3;
    }
    lli ans=0;
    size = (size-3)/2;
    int i=n;
    while(x>0){
        if(x == 2*size+3){
            ans += vec[i];
            break;
        }
        else if(x>1+size){
            ans += vec[i-1]+1;
            x-=size+1;
        }
        i--;
        x-=1;
        size = (size-3)/2;
    }
    printf("%lld", ans);


}