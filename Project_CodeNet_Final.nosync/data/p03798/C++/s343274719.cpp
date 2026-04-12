#include<bits/stdc++.h>
using namespace std;
int main(){
    long n; cin>>n;
    string s; cin>>s;
    s.insert(0,"0");
    vector<string> c={"SS","WW","SW","WS"};
    for(auto x:c){
        string a(n+1,'0');
        a[0]=x[0],a[1]=x[1];
        char t=a[0];
        for(int i=1;i<=n;i++){
                long nx;
                if(i!=n)
                        nx=i+1;
                else{
                        nx=0;
                        if(a[i]!=a[nx]){
                                a[0]='0';
                                break;
                        }
                }
                if(a[i]=='S'){
                        if(s[i]=='o')
                                a[nx]=a[i-1];
                        else{
                                if(a[i-1]=='S')
                                        a[nx]='W';
                                else
                                        a[nx]='S';
                        }
                }
                else{
                        if(s[i]=='x')
                                a[nx]=a[i-1];
                        else{
                                if(a[i-1]=='S')
                                        a[nx]='W';
                                else
                                        a[nx]='S';
                        }
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