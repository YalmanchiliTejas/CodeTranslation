#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
const int INF=1e9;

int main(){
    int h,w;cin>>h>>w;
    vector<string> a(h);
    for(int i=0;i<h;i++) cin>>a[i];
    int c=0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(a[i][j]=='#') c++;
        }
    }
    if(c==h+w-1){
        cout<<"Possible"<<endl;
    }else{
        cout<<"Impossible"<<endl;
    }
    return 0;
}