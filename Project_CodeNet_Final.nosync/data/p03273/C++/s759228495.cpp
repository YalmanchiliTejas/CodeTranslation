#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;

int main(){
    int H,W;
    cin>>H>>W;
    string dots(W,'.');
    vector<string> ans;
    for(int i=0;i<H;i++){
        string x;
        cin>>x;
        if(x!=dots) ans.push_back(x);
    }

    H=ans.size();
    //for(int i=0;i<H;i++) cout<<ans.at(i)<<endl;
    //cout<<H;
    vector<bool> y(W,false);
    for(int i=0;i<W;i++){
        for(int j=0;j<H;j++){
            if(ans.at(j).at(i)=='#') y.at(i)=true;
        }
    }
    //for(int i=0;i<W;i++) cout<<y.at(i)<<' ';

    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if (y.at(j)) cout<<ans.at(i).at(j);
        }
        cout<<endl;
    }
}