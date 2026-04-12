#include <cstdio>
#include <cstring>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <limits.h>
#include <vector>
#include <set>
#include <stack>
#include <queue>

using namespace std;                

#define rep(i,a,b) for(int i = a; i < b; i++)
#define mp make_pair
#define pb push_back

typedef long long lld;
typedef long double llf;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(void){
    
    int N,ans=1;
    bool check;
    int inn[25];
    cin>>N;
    rep(i,1,N+1) cin>>inn[i];
    
    rep(i,2,N+1){
        check = true;
        rep(j,1,i){
            if(inn[j]>inn[i]){
                check = false;
                break;
            }   
        }
        if(check) ans++;
    }
    cout<<ans;
    return 0;	
}
