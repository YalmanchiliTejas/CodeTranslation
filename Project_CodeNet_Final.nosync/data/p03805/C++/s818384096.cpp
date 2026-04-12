#include<cstdio>
#include<cmath>
#include<string>
#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#include<map>
#include<set>
#include<limits>
#include<bitset>
#include<array>
#include<numeric>
#include<iomanip>

using namespace std;
typedef long long int ll;

int n,m,a,b,g,r;
bool ft[10][10];
vector<vector<int>> q={},qb;
vector<int> qm;

int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d %d",&a,&b);
        ft[a][b]=true;
        ft[b][a]=true;
    }

    q.push_back({1,1,0,0,0,0,0,0,0,0,0});
    //place , bit
    
    while(q.size()!=0){
        qb={};
        for(auto itr:q){
            for(int i=1;i<=n;i++){
                if(ft[itr[0]][i] and itr[i]==0){
                    qm={i};
                    for(int j=1;j<=n;j++)qm.push_back(itr[j]);
                    qm[i]=1;
                    g=0;
                    for(int j=1;j<=n;j++){
                        g+=qm[j];
                    }
                    if(g==n)r++;
                    else{
                        qb.push_back(qm);
                    }
                    //for(int j=0;j<=n;j++)printf("%d ",qm[j]);
                    //cout<<" ";
                    
                }
            }
        }
        q=qb;
        //cout<<endl;
    }
    printf("%d\n",r);
    
}