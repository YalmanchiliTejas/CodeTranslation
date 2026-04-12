#include<bits/stdc++.h>
typedef long long ll;
#define INF 100000000
#define MOD 100000007
int dx[4]={1,0,-1,0},dy[4]={0,-1,0,1};
using namespace std;
int main(void){
    int n;
    cin>>n;
    int h[n];
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    int max_height=h[0];
    int ans=0;
    for(int i=0;i<n;i++){
        if(h[i]>=max_height){
            ans++;
            max_height=h[i];
        }
    }
    cout<<ans<<endl;
   return 0;
}