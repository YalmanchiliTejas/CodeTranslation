#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=350;
int main(){
    int n,x,maxx=0,cnt=0;;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        if(maxx<=x){
            cnt++;
            maxx=x;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
