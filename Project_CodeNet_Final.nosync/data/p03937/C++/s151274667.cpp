#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <stack>
#include <functional>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#include <numeric>

#define rep(i,j,k) for(int i=(int)j;i<(int)k;i++)
#define Sort(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define vi vector<int>
#define INF (int)1e9
#define INFL 1e18
#define MOD 1000000007
#define pb push_back
#define MP make_pair
typedef long long int ll;
typedef std::pair<int,int> P;
int D=1;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};

using namespace std;

int main(){
    int h,w;
    cin>>h>>w;
    int sum=0;
    rep(i,0,h)rep(j,0,w){
        char c;
        cin>>c;
        if(c=='#')sum++;
    }
    if(sum==h+w-1)cout<<"Possible"<<endl;
    else cout<<"Impossible"<<endl;
    return 0;
}
