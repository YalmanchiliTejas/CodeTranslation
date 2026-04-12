#include<iostream>
#include<math.h>
#include<vector>
#include<array>
#include<algorithm>
#include<numeric>
#include<map>
#include<queue>
#include<deque>
#include<set>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vector<ll>> mat;

mat memo(110,vec(110,-1));

ll comb(int i,int j){
    if(i<j)return 0;
    if(j==0)return 1;
    if(i==j)return 1;
    if(memo[i][j]!=-1)return memo[i][j];

    return memo[i][j]=(comb(i-1,j)+comb(i-1,j-1));
}

int main(){
    string N;cin>>N;
    int S=N.size();
    int K;cin>>K;
    ll ans=0;
    int k=0,i=0;
    while(k<K && i<S){
        int a=N[i]-'0';
        if(a>0){
            ans+=(a-1)*pow(9,K-k-1)*comb(S-1-i,K-k-1)+pow(9,K-k)*comb(S-1-i,K-k);
            k++;i++;
        }
        else{
            i++;
        }
    }
    if(k==K)ans++;
    cout<<ans<<endl;
    return 0;
}