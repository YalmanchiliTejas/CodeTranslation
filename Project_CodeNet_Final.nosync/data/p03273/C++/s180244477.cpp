#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,i,j,f=0;
    cin>>n>>m;
    char a[n][m];
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    vector<int>r,c;
    for(i=0;i<n;i++){
        if(a[i][0] != '.')continue;
        int x=1;
        for(j=1;j<m;j++){
            if(a[i][j] == '.' && a[i][j-1] == '.'){
                x++;
            }
            else{
                break;
            }
        }
        if(x==m){
            r.push_back(i);
        }
    }
    for(i=0;i<m;i++){
        if(a[0][i] != '.')continue;
        int x=1;
        for(j=1;j<n;j++){
            if(a[j][i] == '.' && a[j-1][i] == '.'){
                x++;
            }
            else{
                break;
            }
        }
        if(x==n){
            c.push_back(i);
        }
    }
    for(i=0;i<n;i++){
        if(binary_search(r.begin(),r.end(),i)){
            continue;
        }
        for(j=0;j<m;j++){
            if(binary_search(c.begin(),c.end(),j)){
                continue;
            }
            cout<<a[i][j];
            f=1;
        }
        cout<<endl;
    }
    return 0;
}