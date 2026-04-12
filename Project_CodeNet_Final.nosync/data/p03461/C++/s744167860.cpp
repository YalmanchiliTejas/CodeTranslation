#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;
const int M=4e3+10;

int n1,n2,w[12][12];


int gw[205][205];


void buildgraph(){
        for(int u1=0;u1<=100;u1++)
                for(int u2=0;u2<=100;u2++){
                        int& rwei=gw[u1][201-u2];
                        for(int w1=1;w1<=n1;w1++)
                                for(int w2=1;w2<=n2;w2++)
                                        rwei=max(rwei,w[w1][w2]-u1*w1-u2*w2);
                }
}
int d[205];
int dijkstra(int w1,int w2){
        d[100]=200;
        for(int i=101;i<=201;i++){
                d[i]=d[i-1]+w2;
                for(int u1=0;u1<=100;u1++) d[i]=min(d[i],gw[u1][i]+u1*w1);
        }
        return d[201];
}
int main(){
        cin>>n1>>n2;
        for(int i=1;i<=n1;i++)
                for(int j=1;j<=n2;j++) cin>>w[i][j];
        buildgraph();
        for(int w1=1;w1<=n1;w1++)
                for(int w2=1;w2<=n2;w2++){
                        if (dijkstra(w1,w2)!=w[w1][w2]) {
                                cout<<"Impossible";
                                return 0;
                        }
        }
        cout<<"Possible\n202 10401\n";
        for(int i=1;i<=100;i++) cout<<i<<" "<<i+1<<" X\n";
        for(int i=102;i<=201;i++) cout<<i<<" "<<i+1<<" Y\n";
        for(int i=0;i<=100;i++)
                for(int j=101;j<=201;j++) cout<<i+1<<" "<<j+1<<" "<<gw[i][j]<<'\n';
        cout<<"1 202";
}
