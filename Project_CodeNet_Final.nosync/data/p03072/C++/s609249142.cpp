#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <iomanip>
#include <map>
#include <stack>
#include <queue>

using namespace std;

typedef long long ll;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n,h[30];
    cin>>n;
    for(int i=0;i<n;i++) cin>>h[i];
    
    int m=h[0];
    int ans=0;
    for(int i=0;i<n;i++){
        if(h[i]>=m){
            m=h[i];
            ans++;
        }
    }
    cout<<ans<<endl;
}