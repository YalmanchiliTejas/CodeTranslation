#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include<iomanip>
#include<tuple>
using namespace std;
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
    int h,w;
    string board[110];
    vector<bool> goodx(110,false),goody(110,false);
    cin>>h>>w;
    for(int i=0;i<h;i++){    
            cin>>board[i];
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(board[i][j]=='#'){
                goodx[i]=true;
                goody[j]=true;
            }
        }
    }
    for(int i=0;i<h;i++){
        if(goodx[i]){
            for(int j=0;j<w;j++){
                if(goody[j]){
                    cout<<board[i][j];
                }
            }
        
    
    cout<<endl;
        }
    }

    return 0;
}