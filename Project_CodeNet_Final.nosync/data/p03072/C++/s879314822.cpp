#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=25;
int main(){
    int a,m[maxn],now,ans=1;
    cin>>a;
    cin>>now;

    for(int i=2;i<=a;i++){
        cin>>m[i];
        if(m[i]>=now){
            now=m[i];
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}