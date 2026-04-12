#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
using namespace std;
typedef long long ll;

int main(){
    int h,w;
     set<int> rmvi,rmvj;
    char a[100][100];
    cin>>h>>w;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<h;i++){
        bool flag=true;
        for(int j=0;j<w;j++){
            if(a[i][j]=='#'){
                flag=false;
                break;
            }
        }
        if(flag)rmvi.insert(i);
    }
    for(int j=0;j<w;j++){
        bool flag=true;
        for(int i=0;i<h;i++){
            if(a[i][j]=='#'){
                flag=false;
                break;
            }
        }
        if(flag)rmvj.insert(j);
    }
    for(int i=0;i<h;i++){
        if(rmvi.find(i)!=rmvi.end())continue;
        for(int j=0;j<w;j++){
            if(rmvj.find(j)!=rmvj.end())continue;
            cout<<a[i][j];
        }
        cout<<endl;
    }
}
