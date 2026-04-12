#include <iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<cctype>
#include<queue>
#include<deque>
#include<regex>
#include<stack>
#include<stdio.h>
#include<vector>
#include<set>
#include<map>
#include<iomanip>

#define rep(i, n) for(int i=0;i<n;i++)

typedef int long long ll;
using namespace std;
typedef pair<int, int> P;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const ll MOD = 1e9 + 7;
static const int MAX = 100;
static const int INF = (1 << 23);

int main() {
    int h,w;
    cin>>h>>w;
    int masu[h][w];
    int sum = 0;
    rep(i,h){
        rep(j,w){
            char c;
            cin>>c;
            if(c=='#'){
               sum++;
            }else{
                masu[i][j]=0;
            }
        }
    }
   
    
    if(sum != h+w-1){
        cout<<"Impossible"<<endl;
    }else{
        cout<<"Possible"<<endl;
    }

    return 0;
}
