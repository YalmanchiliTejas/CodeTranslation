#include<iostream>
#include<stdio.h>
//#include <bits/stdc++.h>
#include<vector>
#include<float.h>
#include<iomanip>
#include<algorithm>
#include<string>
#include<cstring>
#include<math.h>
#include<cmath>
#include<sstream>
#include<set>
#include<map>
#include<queue>
#include <cassert>
#include <cmath>
#include<cstdint>

#define INF 1e9
#define rep(i,n)for(int i=0;(i)<(int)(n);i++)
#define REP(i,a,b)for(int i=(int)(a);(i)<=(int)(b);i++)
#define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)std::cin>>i;
#define vec(type,n) vector<type>(n)
#define vvec(m,n) vector<vector<int>> (int(m),vector<int>(n))
#define ALL(a)  (a).begin(),(a).end()

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int,int>;

vector<int>bitSearch(int bit,int n){
    vector<int>S;
    rep(i,n)if(bit&(1<<i))S.push_back(i);
    return S;
}

template<typename A,size_t N,typename T>
void Fill(A(&array)[N],const T &val){
    fill((T*)array,(T*)(array+N),val);
}

ll res;
ll solve(ll n,ll x){
    if(x<=0 || n<=0)return res;
    if(n==1){
        return min((int)(x-1),3);
    }
    if(x<pow(2,n+1)-1){
        return solve(n-1,x-1);
    }
    else if(x==pow(2,n+1)-1){
        //res += pow(2,n);
        return pow(2,n);
    }
    else {
        //res += pow(2,n);
        return pow(2,n)+solve(n-1,x-pow(2,n+1)+1);
    }
}
int main(){
    ll n,x;cin>>n>>x;
    cout<<solve(n,x)<<endl;
}