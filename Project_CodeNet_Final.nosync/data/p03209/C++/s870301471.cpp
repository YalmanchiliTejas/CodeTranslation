#include<iostream>
#include<set>
#include <bitset>
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
#include <limits>
#include <numeric>
#include <type_traits>
#define int long long
#define ll long long
#define mod  1000000007
#define inf 1e17
#define rep(i,j,n) for(int i=j;i<n;i++)
#define P pair<int,int>
#define ps push_back
double pi = 3.141592653589793;
using namespace std;
int z=0;
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    fill( (T*)array, (T*)(array+N), val );
}
//ここから始めよう
int n,x;int sl[55];
int solve(int l,int a){
    if(l==0&&a==1)return 1;
    else if(a==1)return 0;
    else if(1<a&&a<=1+sl[l-1]){
        return solve(l-1,a-1);
    }
    else if(a==2+sl[l-1])return solve(l-1,sl[l-1])+1;
    else if(2+sl[l-1]<a&&a<=2+2*sl[l-1]){
        return solve(l-1,sl[l-1])+1+solve(l-1,a-2-sl[l-1]);
    }else return 2*solve(l-1,sl[l-1])+1;
}
signed main(){
    cin>>n>>x;
    sl[0]=1;
    rep(i,1,n+1){
        sl[i]=2*sl[i-1]+3;
    }
    cout<<solve(n,x)<<endl;return 0;
}
