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
#include<string.h>
#include <cmath>
#include <iomanip>
#include <string>
#include<list>
using namespace std;
#define int long long
#define inf 1000000007
#define rep(i,j,n) for(int i=j;i<n;i++)
typedef pair<int,int>  P;
double pi = 3.141592653589793;
//使うやつはここから下に置こうなh
signed main(){
    int h,w;cin>>h>>w;
    int count=0;
    rep(i,0,h)rep(j,0,w){
        char f;cin>>f;
        if(f=='#')count++;
    }
    if(count==h+w-1)cout<<"Possible"<<endl;
    else cout<<"Impossible"<<endl;
    return 0;
}