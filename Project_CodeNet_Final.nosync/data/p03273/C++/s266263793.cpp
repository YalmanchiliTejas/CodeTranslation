#include <cstdio>
#include <cstring>
#include <cmath>
#include <utility>
#include <iostream>
#include <functional>
#include <bitset>
#include <algorithm>
#include <vector>
#include <forward_list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <numeric>
#define ll long long int
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
int mx4[] = {0,1,0,-1};
int my4[] = {1,0,-1,0};


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main(){
    int h,w,k = 0,tp = 0; cin >> h >> w;
    char a[h][w];
    rep(i,h){
        rep(j,w){
            cin >> a[i][j];
        }
    }
    rep(i,h){
        bool yoko = true;
        rep(j,w){
            if(a[i][j] == '#'){
                yoko = false;
                break;
            }
        }
        if(yoko){
            rep(k,w){
                a[i][k] = 'p';
            }
        }
    }

    rep(i,w){
        bool tate = true;
        rep(j,h){
            if(a[j][i] == '#'){
                tate = false;
                break;
            }
        }
        if(tate){
            rep(k,h){
                a[k][i] = 'p';
            }tp++;
        }
    }
  
  char ans[h*w];
  rep(i,h){
        int kai = 0;
        rep(j,w){
            if(a[i][j] == 'p') continue;
            else{
                    ans[k] = a[i][j];
                    k++;
            }
        }
    }
    cout << ans[0];
    for(int i=1;i<k;i++){
        if(i % (w-tp) == 0){
            cout << endl;
          	cout << ans[i]; 
        }else{
            cout << ans[i];
        }
    }
}