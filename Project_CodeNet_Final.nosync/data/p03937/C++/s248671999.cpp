#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
#include <functional> 
#include <vector>
#include <numeric>
#include <stack>
#include <queue>
#include <utility>
#include <map>
#include <cstdlib>
typedef long long ll;
#define fi first
#define se second
#define SORT(a) sort(a.begin(),a.end())
 
using namespace std;
 
int main(){
 
    int h,w;
    cin >> h >> w;

    char a[h+2][w+2];
    for(int i=0;i<h+2;i++){
        for(int j=0;j<w+2;j++){
            if(i == 0 || i == h+1 || j == 0 || j == w+1) a[i][j] = '.';
            else cin >> a[i][j];
        }
    }

    int px = 1,py =1;
    while(1){
        if(!(a[px-1][py+1] == '.' && a[px-1][py] == '.' && a[px-1][py-1] == '.' && a[px][py-1] == '.' && a[px+1][py-1] == '.')){
            cout << "Impossible";
            return 0;
        }
        if(px == h && py == w){
            cout << "Possible";
            return 0;
        }
        if(a[px][py+1] == '#' && a[px+1][py] == '#'){
            cout << "Impossible";
            return 0;
        }else if(a[px][py+1] == '#'){
            a[px][py] = '.';
          	py++;
            
        }else if(a[px+1][py] == '#'){
            a[px][py] = '.';
          	px++;
            
        }
    }
    return 0;
}