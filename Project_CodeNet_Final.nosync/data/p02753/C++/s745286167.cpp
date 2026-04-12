#include<bits/stdc++.h>
using namespace std;
int main(){

     long long int a,b,c,d,e,f,i,j,t=0,u=0;
     string x,y;
     vector<int> v;
     vector<int> v1;
     vector<int> v2;
     cin>>x;
     for(i=0;i<x.length();i++){
        if(x[i]=='A')
            t++;
        else if(x[i]=='B')
            u++;
     }
     if(t>=1 && u>=1){
        cout<<"Yes"<<endl;
     }
     else cout<<"No"<<endl;

    return 0;
}

