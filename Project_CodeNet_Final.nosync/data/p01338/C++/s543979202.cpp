#include<bits/stdc++.h>
using namespace std;

struct NODE{
    int m[7];

    bool operator<(const NODE &n)const{
        for(int i=0;i<7;i++)if(m[i]!=n.m[i])return m[i]<n.m[i];
        return false;
    }
};

int to[]={0,2,3,4,1};
int table[]={0,60,10,10,-80};
int score[]={0,0,60,70,80};
int fld[5][5];

void solve(){
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            cin>>fld[i][j];

    map<NODE,int>prev;
    NODE start;
    for(int i=0;i<5;i++)start.m[6-i]=fld[0][i];
    for(int i=0;i<2;i++)start.m[1-i]=fld[1][i];
    int sum=0;
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            sum+=score[fld[i][j]];
    prev[start]=sum;

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            map<NODE,int>next;
            for(map<NODE,int>::iterator it=prev.begin();it!=prev.end();it++){

                NODE d=it->first;
                int val=it->second;
                for(int k=0;k<4;k++){
                    for(int l=0;l<7;l++)if(l<2||l>=5){

                        val+=table[d.m[l]];
                        d.m[l]=to[d.m[l]];
                    }
                    NODE e=d;
                    if(j!=3){
                        for(int l=6;l>0;l--)e.m[l]=e.m[l-1];
                        e.m[0]=fld[i+1][j+2];
                    }
                    else{
                        for(int l=6;l>1;l--)e.m[l]=e.m[l-2];
                        e.m[1]=fld[i+2][0];
                        e.m[0]=fld[i+2][1];
                    }
                    if(next.find(e)!=next.end())next[e]=max(next[e],val);
                    else next[e]=val;
                }
            }
            prev=next;
        }

    }

    int ans=0;
    for(map<NODE,int>::iterator it=prev.begin();it!=prev.end();it++){
        ans=max(ans,it->second);
    }

    cout<<ans<<endl;


}
int main(){
    int n;
    cin>>n;

    while(n--)solve();
    return 0;
}