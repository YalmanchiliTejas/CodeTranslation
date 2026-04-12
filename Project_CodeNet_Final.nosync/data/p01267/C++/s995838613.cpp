#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a,b,c,x;
    int cnt,y[105];
    while(1){
        cin>>n>>a>>b>>c>>x;
        cnt=0;
        if(n==0 && a==0 && b==0 && c==0 && x==0){break;}
        for(int i=0;i<n;i++){
            cin>>y[i];
        }
        int i;
        for(i=0;i<10002;i++){
            if(x==y[cnt]){
                cnt++;
            }
            if(cnt==n){break;}
            x=(a*x+b)%c;
        }
        if(cnt==n && i < 10001){
            cout<<i<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
    return 0;
}

