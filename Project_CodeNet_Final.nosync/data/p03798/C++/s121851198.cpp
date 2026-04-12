#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include <numeric>
#include<map>
#include<unordered_map>
 
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<n;++i)
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define ALL(a) (a).begin(),(a).end()

int main(){
    ll n;
    cin >> n;
    string s;
    cin >> s;

    vector<bool> a[4];
    a[0].push_back(true);
    a[0].push_back(true);
    a[1].push_back(true);
    a[1].push_back(false);
    a[2].push_back(false);
    a[2].push_back(true);
    a[3].push_back(false);
    a[3].push_back(false);
    rep(i, 4){
        for(int j = 1; j < n; j++){
            if(j == n-1)break;
            if(a[i][j]){
                if(s[j] == 'o')a[i].push_back(a[i][j-1]);
                else a[i].push_back(!a[i][j-1]);
            }
            else{
                if(s[j] == 'o')a[i].push_back(!a[i][j-1]);
                else a[i].push_back(a[i][j-1]);
            }
        }
    }

    // rep(i, 4){
    //     rep(j, n){
    //         if(a[i][j])cout << "S";
    //         else cout << "W";
    //     }cout << endl;
    // }
    rep(i, 4)rep(j, n){
        bool next;
        if(j == 0)next = (a[i].back()^a[i][j+1]);
        else if(j == n-1)next = (a[i].front()^a[i][j-1]);
        else next = (a[i][j-1]^a[i][j+1]);
        if(a[i][j]){
            if(s[j] == 'o' && next)break;
            if(s[j] == 'x' && !next)break;
        }
        else{
            if(s[j] == 'o' && !next)break;
            if(s[j] == 'x' && next)break;
        }
        if(j == n-1){
            rep(k, n){
                if(a[i][k])cout << "S";
                else cout << "W";
            }
            return 0;
        }
    }
    cout << -1;


}