#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);
    int h,w,a[105]={},b[105]={};
    string s[105];
    cin>>h>>w;
    for(int i=0;i<h;i++){
        cin>>s[i];
    }
    for(int i=0;i<h;i++){
        int c=0;
        for(int j=0;j<w;j++){
            if(s[i][j]=='.')
                c++;
        if(c==w)
            a[i]=1;
        }
    }
    for(int i=0;i<w;i++){
        int c=0;
        for(int j=0;j<h;j++){
            if(s[j][i]=='.')
                c++;
        if(c==h)
            b[i]=1;
        }
    }
    for(int i=0;i<h;i++){
        int c=0;
        for(int j=0;j<w;j++){
            if(a[i]!=1 && b[j]!=1){
                cout<<s[i][j];
                c++;
            }
        }
        if(c!=0)
            cout<<endl;
    }
    return(0);
}