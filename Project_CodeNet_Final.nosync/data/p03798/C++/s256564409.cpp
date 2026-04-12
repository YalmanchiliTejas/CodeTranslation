#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int INF=1e9;

int main(){
    int n;
    string s;
    cin>>n>>s;
    int a[n];
    for(int i=0;i<4;i++){
        a[0]=i%2;
        a[1]=i/2;
        for(int i=1;i<n-1;i++){
            if(s[i]=='o')a[i+1]=a[i-1];
            else a[i+1]=a[i-1]^1;
            if(a[i])a[i+1]^=1;
        }
        bool can=true;
        if(s[n-1]=='o'){
            if(a[n-1]&&a[n-2]==a[0])can=false;
            else if(!a[n-1]&&a[n-2]!=a[0])can=false;
        }
        else{
            if(a[n-1]&&a[n-2]!=a[0])can=false;
            else if(!a[n-1]&&a[n-2]==a[0])can=false;
        }
        if(s[0]=='o'){
            if(a[0]&&a[n-1]==a[1])can=false;
            else if(!a[0]&&a[n-1]!=a[1])can=false;
        }
        else{
            if(a[0]&&a[n-1]!=a[1])can=false;
            else if(!a[0]&&a[n-1]==a[1])can=false;
        }
        if(can){
            for(int i=0;i<n;i++){
                if(a[i]==0)cout<<'S';
                else cout<<'W';
            }
            cout<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
}
