#include <numeric>
#include<iostream>
#include<set>
#include<queue>
#include<vector>
#include<map>
#include<stack>
#include <cstdio>
#include<algorithm>
#include <sstream>
#include<string>
#include <cmath>
#include <iomanip>
#include <string>
#include<list>
using namespace std;
#define inf 1000000007
#define int long long
#define rep(i,j,n) for(int i=j;i<n;i++)
typedef pair<int,int>  p;
struct edge{int to,cost;};
double pi = 3.141592653589793;
//使うやつはここから下に置こうな

signed main(){
    int n;cin>>n;
    int num[214514];
    int key[214514];
    rep(i,0,n){
        cin>>num[i];key[i]=num[i];
    }
    sort(key,key+n);
    int sm=key[n/2-1],bi=key[n/2];
    rep(i,0,n){
        if(num[i]<=sm)cout<<bi<<endl;
        else if(num[i]>=bi)cout<<sm<<endl;
    }
    return 0;
}