#include<bits/stdc++.h>
using namespace std;
int main(){
    long n; cin>>n;
    string s; cin>>s;
    s.insert(0,"0");
    vector<string> c={"SS","WW","SW","WS"};
    for(auto x:c){
        string a(n+1,0);
        a[0]=x[0],a[1]=x[1];
        for(int i=1;i<=n;i++){
                long nx=(i+1)%(n+1);
                if(i==n){
                        if(a[i]!=a[nx]){
                                a[0]='0';
                                break;
                        }
                }
                bool j;
                if(s[i]=='o')
                        j=true;
                else
                        j=false;
                if(a[i]=='W')
                        j=!j;
                if(j)
                        a[nx]=a[i-1];
                else{
                        if(a[i-1]=='S')
                                a[nx]='W';
                        else
                                a[nx]='S';
                }
        }
        if(a[0]==a[1]){
                        for(int j=1;j<=n;j++)
                                cout<<a[j];
                        return 0;
        }
    }
    cout<<-1;
}