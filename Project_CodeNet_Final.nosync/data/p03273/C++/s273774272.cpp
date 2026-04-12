#include <bits/stdc++.h>
using namespace std;
int main(){
    int H,W,i,j;
    cin>>H>>W;
    vector<string> M(H);
    for(i=0;i<H;i++) cin>>M.at(i);
    for(i=0;i<W;i++){
        for(j=0;j<H;j++)
            if(M.at(j).at(i)=='#') goto loop_1;
        for(j=0;j<H;j++)
            M.at(j).erase(i,1);
        W--;
        i--;
        loop_1:;
    }
    for(i=0;i<H;i++){
        for(j=0;j<W;j++)
            if(M.at(i).at(j)=='#') goto out;
        goto noout;
        out: cout<<M.at(i)<<endl;
        noout:;
    }
}
