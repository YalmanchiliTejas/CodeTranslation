#include<bits/stdc++.h>
using namespace std;

using pii=pair<int,int>;
using ppp=pair<pii,pii>;

int main(){
    int n;
    cin>>n;
    vector<int> h(n),w(n);
    for(int i=0;i<n;i++){
        cin>>h[i]>>w[i];
    }
    vector<string> c(4);
    for(int i=0;i<4;i++) cin>>c[i];
    vector<vector<int>> tar(4,vector<int>(4));
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(c[i][j]=='R') tar[i][j]=0;
            if(c[i][j]=='G') tar[i][j]=1;
            if(c[i][j]=='B') tar[i][j]=2;
        }
    }
    set<ppp> s;
    for(int k=0;k<n;k++){
        for(int i=-3;i<4;i++){
            for(int j=-3;j<4;j++){
                int u=max(i,0);
                int b=min(4,i+h[k]);
                int l=max(j,0);
                int r=min(4,j+w[k]);
                if(u!=b && l!=r) s.insert(ppp(pii(u,b),pii(l,r)));
            }
        }
    }

    vector<ppp> stamp(s.begin(),s.end());
    const int INF=1e8;
    vector<int> d(1<<16,INF);
    d[0]=0;

    queue<int> que;
    que.push(0);

    while(!que.empty()){
        int st=que.front(); que.pop();
        for(int k=0;k<stamp.size();k++){
            int u=stamp[k].first.first,b=stamp[k].first.second;
            int l=stamp[k].second.first,r=stamp[k].second.second;
            for(int c=0;c<3;c++){
                int to=st;
                for(int i=u;i<b;i++){
                    for(int j=l;j<r;j++){
                        int pos=i*4+j;
                        if(tar[i][j]!=c){
                            to&=(~(1<<pos));
                        }
                        else{
                            to|=(1<<pos);
                        }
                    }
                }
                if(d[st]+1<d[to]){
                    d[to]=d[st]+1;
                    que.push(to);
                }
            }
        }
    }
    cout<<d[(1<<16)-1]<<endl;

    return 0;
}
