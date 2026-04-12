#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include <numeric>
#include<map>
#include<unordered_map>
#include <queue>
 
using namespace std;
using ll=long long;
#define rep(i,n)  for(ll i=0;i<n;++i)
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define ALL(a) (a).begin(),(a).end()

int main(){
    int h, w;
    cin >> h >> w;
    string a[h];
    rep(i, h)cin >> a[i];
    ll cnt = 0;
    rep(i, h)rep(j, w)if(a[i][j]=='#')cnt++;

    ll pos =  0;
    ll path = 0;
    rep(i, h){
        while(a[i][pos]=='#')pos++, path++;
        pos--;
        if(i == h-1)break;
        else if(a[i+1][pos]!='#')break;
    }
    if(cnt == path)cout << "Possible\n";
    else cout << "Impossible\n";

}