#include <cmath>
#include<vector>
#define rep(i, n) for (int i=0;i<n;i++)
#include <map> 
#include<algorithm>
#include <numeric>
#include<iostream>
#include<deque>
#include<queue>
#include<string>
#include <iomanip>
using namespace std;
typedef long long ll;

int main(void){
    int n;
    cin>>n;
    vector <int> v(n);
    rep(i, n){
        cin>>v[i];
    }
    int maxh=0;
    int ans=1;
    rep(i, n-1){
        maxh=max(maxh, v[i]);
        if(v[i+1]>=maxh) ans++;
    }
    cout<<ans<<endl;
}