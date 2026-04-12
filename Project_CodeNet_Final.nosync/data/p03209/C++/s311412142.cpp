#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
typedef long long int ll;

int n;
ll x;
ll sum=0;
ll a[51],p[51];
void dfs(int n,ll rest){
    if(rest<=1)return;
    rest--;
    if(rest>=a[n-1]){
        sum+=p[n-1];
        rest-=a[n-1];
    }
    else{
        dfs(n-1,rest);
        rest=0;
    }
    if(rest<=0)return;
    rest--;
    sum++;
    if(rest>=a[n-1]){
        sum+=p[n-1];
        rest-=a[n-1];
    }
    else{
        dfs(n-1,rest);
        rest=0;
    }
    if(rest<=0)return;
}

int main(){
    cin >> n >> x;
    a[0]=1;
    p[0]=1;
    for(int i=1;i<=50;i++){
        a[i]=a[i-1]*2+3;
        p[i]=p[i-1]*2+1;
    }
    dfs(n,x);
    cout << sum << endl;
}