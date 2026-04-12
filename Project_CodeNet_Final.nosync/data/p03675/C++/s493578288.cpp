


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
typedef long long ll;
int mod(ll a){return a%1000000007;};
typedef pair<int,int> i_i;


int main(){
    int n;cin>>n;
    int a[n+1];for(int i=1;i<=n;i++)cin>>a[i];
    int b[n+1];
    if(n%2==0){
        for(int i=1;i<=n/2;i++){
            b[i]=a[n-2*i+2];
        }
        for(int i=1;i<=n/2;i++){
            b[n/2+i]=a[2*i-1];
        }
    }else{
        for(int i=1;i<=n/2+1;i++){
            b[i]=a[n-(2*i)+2];
        }
        for(int i=1;i<=n/2;i++){
            b[n/2+1+i]=a[2*i];
        }
    }
    for(int i=1;i<=n;i++)cout<<b[i]<<" ";
    
    return 0;
}
