#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include <algorithm>
using namespace std;
using ll = long long;

typedef pair<int,int> P;
 
int main(void){
    int N;
    cin >> N;
    vector<ll> vec(N);
    ll ans=0;
    ll X=1000000007;
    ll fix=0;
    for(int k=0;k<N;k++){
        cin >> vec[k];
    }
    for(int m=0;m<N;m++){
        fix+=vec[m];
        fix%=X;
    }
    for(int m=0;m<N;m++){
        ll preans=0;
        fix-=vec[m];
        if(fix<0)fix+=X;
        preans=vec[m]*fix;
        preans%=X;
        ans+=preans;
        ans%=X;
    }
    cout <<ans<<endl;
}