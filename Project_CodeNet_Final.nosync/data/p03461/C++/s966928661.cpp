#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
struct edge{
    int x,y,u;
};
vector<edge> conn;
const int MAX=12,INF=0x3f3f3f3f;
int a,b,d[MAX][MAX],d_est[MAX][MAX],d_est2[MAX][MAX],val[110][110],x_max,y_max;
int update(int x,int y,int z){
    if(x<0||y<0||z<0) return 0;
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            d_est2[i][j]=min(d_est[i][j],z+i*x+j*y);
            if(d[i][j]>d_est2[i][j]) return 0;
        }
    }
    val[x][y]=z;
    for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) d_est[i][j]=d_est2[i][j];
    return 1;
}
int main(){
    scanf(" %d %d",&a,&b);
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++) scanf(" %d",&d[i][j]);
    }
    for(int i=0;i<=100;i++) for(int j=0;j<=100;j++) val[i][j]=-1;
    for(int i=0;i<=a;i++) for(int j=0;j<=b;j++) d_est[i][j]=INF;
    for(int i=a;i>=1;i--){
        for(int j=b;j>=1;j--){
            int x,y,z,chk=0;
            for(x=0;x<=100&&!chk;x++) for(y=0;y<=100&&!chk;y++) {
                z=d[i][j]-x*i-y*j;
                if(update(x,y,z)) chk=1;
            }
            if(!chk){
                printf("Impossible\n");
                return 0;
            }
        }
    }
    printf("Possible\n");
    for(int i=0;i<=100;i++) for(int j=0;j<=100;j++){
        if(val[i][j]>=0) x_max=max(i,x_max),y_max=max(j,y_max);
    }
    for(int i=1;i<=x_max;i++) conn.push_back({i,i+1,-1});
    for(int i=x_max+2;i<=x_max+y_max+1;i++) conn.push_back({i+1,i,-2});
    for(int i=0;i<=100;i++) for(int j=0;j<=100;j++){
        if(val[i][j]>=0) conn.push_back({i+1,x_max+2+j,val[i][j]});
    }
    printf("%d %d\n",x_max+y_max+2,conn.size());
    for(int i=0;i<conn.size();i++){
        if(conn[i].u==-1) printf("%d %d X\n",conn[i].x,conn[i].y);
        else if(conn[i].u==-2) printf("%d %d Y\n",conn[i].x,conn[i].y);
        else printf("%d %d %d\n",conn[i].x,conn[i].y,conn[i].u);
    }
    printf("%d %d\n",1,x_max+2);
}
