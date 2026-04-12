#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
int n;
ll OO=1000000000000;
int a[3000];
ll mem[3007][3007];
ll solve(int i,int j){
     if(i==j) {
            return a[i];
     }
     if(mem[i][j]!=OO)return mem[i][j];

        mem[i][j]=max(a[i]-solve(i+1,j),a[j]-solve(i,j-1));
        return mem[i][j];
}
int main()
{
    for(int i=0;i<3007;i++){
        for(int j=0;j<3007;j++){
            mem[i][j]=OO;
        }
    }
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    cout<<solve(0,n-1);
}
