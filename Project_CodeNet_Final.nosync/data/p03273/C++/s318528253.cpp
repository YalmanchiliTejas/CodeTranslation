#include<bits/stdc++.h>
using namespace std;
int main(){
    int h,w;
    cin>>h>>w;
    vector<string> a(h);
    for(int i=0;i<h;i++){
            cin>>a[i];
    }
    vector<bool> col(h,0);
    vector<bool> row(w,0);
    for(int i=0;i<h;i++){
        if(count(a[i].begin(),a[i].end(),'.')==w)col[i]=1;
    }
    for(int i=0;i<w;i++){
        int count=0;
        for(int j=0;j<h;j++){
            if(a[j][i]=='.')count++;
        }
        if(count==h)row[i]=1;
    }
    for(int i=0;i<h;i++){
        if(col[i])continue;
        for(int j=0;j<w;j++){
            if(!row[j])cout<<a[i][j];
        }
        cout<<endl;
    }
    return 0;
}
