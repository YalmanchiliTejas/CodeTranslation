#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=20005,INF=1<<20;

int par[MAX],size[MAX];

void init(int n){
    for(int i=0;i<n;i++){
        par[i]=i;
        size[i]=1;
    }
}

int root(int a){
    if(par[a]==a) return a;
    else return par[a]=root(par[a]);
}

void unite(int a,int b){
    if(root(a)!=root(b)){
        size[root(a)]+=size[root(b)];
        par[root(b)]=root(a);
    }
}

bool check(int a,int b){
    return root(a)==root(b);
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    while(1){
        int N;cin>>N;
        if(N==0) break;
        map<int,int> MX,MY;
        vector<int> X1(N),Y1(N),X2(N),Y2(N);
        
        for(int i=0;i<N;i++){
            int x1,y1,x2,y2;cin>>x1>>y2>>x2>>y1;
            MX[x1]=1;
            MX[x2]=1;
            MY[y1]=1;
            MY[y2]=1;
            
            X1[i]=x1;
            Y1[i]=y1;
            X2[i]=x2;
            Y2[i]=y2;
        }
        int idx=1,idy=1;
        for(auto it=MX.begin();it!=MX.end();it++,idx++){
            MX[(*it).first]=idx;
        }
        for(auto it=MY.begin();it!=MY.end();it++,idy++){
            MY[(*it).first]=idy;
        }
        
        for(int i=0;i<N;i++){
            X1[i]=MX[X1[i]];
            Y1[i]=MY[Y1[i]];
            X2[i]=MX[X2[i]];
            Y2[i]=MY[Y2[i]];
        }
        
        init(idx*idy);
        
        set<pair<int,int>> out;
        
        for(int i=0;i<N;i++){
            for(int j=Y1[i];j<Y2[i];j++){
                out.insert({X1[i]-1+j*idx,X1[i]+j*idx});
                out.insert({X2[i]-1+j*idx,X2[i]+j*idx});
            }
            
            for(int j=X1[i];j<X2[i];j++){
                out.insert({j+(Y1[i]-1)*idx,j+Y1[i]*idx});
                out.insert({j+(Y2[i]-1)*idx,j+Y2[i]*idx});
            }
        }
        
        for(int j=0;j<idy;j++){
            for(int i=0;i+1<idx;i++){
                if(out.count({i+j*idx,i+1+j*idx})==0){
                    unite(i+j*idx,i+1+j*idx);
                }
            }
        }
        
        for(int i=0;i<idx;i++){
            for(int j=0;j+1<idy;j++){
                if(out.count({i+j*idx,i+(j+1)*idx})==0){
                    unite(i+j*idx,i+(j+1)*idx);
                }
            }
        }
        set<int> SE;
        
        for(int i=0;i<idx*idy;i++){
            SE.insert(root(i));
            //cout<<i<<" "<<root(i)<<endl;
        }
        
        cout<<SE.size()<<endl;
    }
}



