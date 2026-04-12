#include<bits/stdc++.h>
using namespace std;

int main(){
    int h,w;
    cin>>h>>w;
    vector<string> c(h);
    for(int i=0;i<h;i++){
        cin>>c[i];
    }

    vector<pair<int,int>> pos;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(c[i][j]=='B'){
                pos.push_back(make_pair(i,j));
                break;
            }
        }
        for(int j=w-1;j>=0;j--){
            if(c[i][j]=='B'){
                pos.push_back(make_pair(i,j));
                break;
            }
        }
    }

    int res=0;
    for(auto p1:pos){
        for(auto p2:pos){
            int d=abs(p1.first-p2.first)+abs(p1.second-p2.second);
            res=max(res,d);
        }
    }
    cout<<res<<endl;
    return 0;
}
