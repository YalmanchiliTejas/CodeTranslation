#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=1LL<<60;
const ll mod=1000000007;
int main(void){
    int n;
    string s;
    cin>>n>>s;
    //S=1,W=2
    for(int x=1;x<=2;x++){
        for(int y=1;y<=2;y++){
            int a[100001]={};
            a[0]=x,a[1]=y;
            for(int i=1;i<n;i++){
                if(a[i]==1){
                    if(s[i]=='o'){
                        a[i+1]=a[i-1];
                    }
                    if(s[i]=='x'){
                        if(a[i-1]==1) a[i+1]=2;
                        else a[i+1]=1;
                    }
                }
                if(a[i]==2){
                    if(s[i]=='x'){
                        a[i+1]=a[i-1];
                    }
                    if(s[i]=='o'){
                        if(a[i-1]==1) a[i+1]=2;
                        else a[i+1]=1;
                    }
                }
            }
            bool ok=false;
            if(a[0]==a[n]){
                if(a[0]==1){
                    if((s[0]=='o'&&a[n-1]==a[1])||(s[0]=='x'&&a[n-1]!=a[1])) ok=true;
                }
                if(a[0]==2){
                    if((s[0]=='x'&&a[n-1]==a[1])||(s[0]=='o'&&a[n-1]!=a[1])) ok=true;
                }
            }
            if(ok){
                for(int i=0;i<n;i++){
                    if(a[i]==1) cout<<'S';
                    else cout<<'W';
                }
                cout<<endl;
                return 0;
            }
        }
    }
    cout<<-1<<endl;
}