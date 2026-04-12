#include <bits/stdc++.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <map>
#include <bitset>
#include <cmath>
#include <set>
#include <utility>
#include <sstream>

#define INF 1000000000000
#define MOD 1000000007 //10^9+7:合同式の法

using namespace std;
typedef long long ll;

//マクロ
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define ALL(x) x.begin(),x.end()
#define chmax(x,y) (x = max(x,y))
#define chmin(x,y) (x = min(x,y))

int main(){
    int H,W;
    cin >> H >> W;

    vector<vector<char>> A(H,vector<char>(W)),hako(H,vector<char>(W)),ans(H,vector<char>(W));

    for(int i = 0;i < H;i++)
        for(int j = 0;j < W;j++)
            cin >> A.at(i).at(j);

    int genzita = 0,hight =0;
    for(int i = 0;i < H;i++){
        int count = 0;
        
        for(int j = 0;j < W;j++){
            if(A.at(i).at(j) == '.')
                count++;
        }

        if(count != W){
            for(int j = 0;j < W;j++){
                hako.at(hight).at(j) = A.at(i).at(j);
                
            }
            hight++;
        }else{
          genzita++;  
        }
    }

    /*for(int i = 0;i < hight;i++){
        for(int j = 0;j < W;j++){
            cout << hako.at(i).at(j);
        }
        cout << endl;
    }

    */

    int yoko = 0;
    for(int i = 0;i < W;i++){
        int count = 0;
        for(int j = 0;j < H-genzita;j++){
            if(hako.at(j).at(i) == '.')
                count++;
        }

        if(count != (H-genzita)){
            for(int j = 0;j < H-genzita;j++){
                ans.at(j).at(yoko) = hako.at(j).at(i);
            }
            yoko++;
        }
    }

    for(int i = 0;i < hight;i++){
        for(int j = 0;j < yoko;j++){
            cout << ans.at(i).at(j);
        }
        cout << endl;
    }


}