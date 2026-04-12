#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
struct rect{
    int x1,y1,x2,y2;
    rect(int x1, int y1, int x2, int y2){
        this->x1=x1; this->y1=y1;
        this->x2=x2; this->y2=y2;
    }
    bool isInclude(double x, double y){
        return x1<=x&&x<=x2&&y2<=y&&y<=y1;
    }
};

vector<double> X,Y;
long long int map[102][102];
bool isChecked[102][102];

void dfs(int y, int x){
    int d[5]={-1,0,1,0,-1};
    if(isChecked[y][x]) return;
    isChecked[y][x]=true;
    for(int i=0;i<4;i++){
        int dx=d[i],dy=d[i+1];
        if(0<=x+dx&&x+dx<=X.size()&&0<=y+dy&&y+dy<=Y.size()){
            if(isChecked[y+dy][x+dx])continue;
            if(map[y+dy][x+dx]==map[y][x]) dfs(y+dy,x+dx);
        }
    }
}

int main(){
    int n;
    vector<rect> R;
    while(cin>>n,n){
        R.clear();
        X.clear(); Y.clear();
        for(int i=0;i<n;i++){
            int l,t,r,b;
            cin>>l>>t>>r>>b;
            R.emplace_back(l,t,r,b);
            X.push_back(l);
            X.push_back(r);
            Y.push_back(t);
            Y.push_back(b);
        }
        X.push_back(-1);
        X.push_back(1e6+1);
        Y.push_back(-1);
        Y.push_back(1e6+1);
        sort(X.begin(),X.end());
        X.erase(unique(X.begin(),X.end()),X.end());
        sort(Y.begin(),Y.end());
        Y.erase(unique(Y.begin(),Y.end()),Y.end());

        fill(map[0],map[102],-1);
        fill(isChecked[0],isChecked[102],false);
        for(int i=0;i<Y.size()-1;i++){
            for(int j=0;j<X.size()-1;j++){
                double x=(X[j]+X[j+1])/2.0, y=(Y[i]+Y[i+1])/2.0;
                long long int region=0;
                for(int i=0;i<n;i++){
                    if(R[i].isInclude(x,y))region|=((long long int)1<<i);
                }
                map[i][j]=region;
            }
        }
        int count =0;
        for(int i=0;i<Y.size()-1;i++){
            for(int j=0;j<X.size()-1;j++){
                if(isChecked[i][j])continue;
                count++;
                dfs(i,j);
            }
        }
        cout<<count<<endl;
    }
    return 0;
}