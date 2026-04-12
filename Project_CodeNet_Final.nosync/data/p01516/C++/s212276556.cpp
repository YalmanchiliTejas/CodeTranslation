#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>
#include<numeric>
#include<queue>
#include<stack>
#include<cmath>
#include<complex>
#define INF 10000000.0
#define pb push_back
using namespace std;
#define all(c) (c).begin(), (c).end()
#define rep(i,n) for(int i=0; i<(int)(n); i++)
typedef complex<double> Point;
typedef pair<double ,int > P;
const double PI=4*atan(1);
vector<vector<Point> > p;
int n,s,g;
double dot(Point a, Point b){
    return real( conj(a) * b );
}
double cross(Point a, Point b){
    return imag( conj(a) * b );
}
double distance_ls_p(Point a, Point b, Point c) {
  if ( dot(b-a, c-a)<=0 ) return abs(c-a);
  if ( dot(a-b, c-b)<=0 ) return abs(c-b);
  return abs(cross(b-a, c-a)) / abs(b-a);
}
int is_intersected_ls(Point a1, Point a2, Point b1, Point b2) {
  return ( cross(a2-a1, b1-a1) * cross(a2-a1, b2-a1) <=0 ) &&
         ( cross(b2-b1, a1-b1) * cross(b2-b1, a2-b1) <=0 );
}
double distance_ls_ls(Point a1,Point a2,Point a3,Point a4){
    if(is_intersected_ls(a1,a2,a3,a4))
        return 0.0;
    double r1=distance_ls_p(a1,a2,a3),r2=distance_ls_p(a1,a2,a4),r3=distance_ls_p(a3,a4,a1),r4=distance_ls_p(a3,a4,a2);
    if(r1>r2)
    r1=r2;
    if(r3>r4)
    r3=r4;
    if(r1>r3)
    return r3;
    return r1;
     
}
double cal(int a,int b){
    double ret=INF;
    for(int i=0;i<5;i++){
        for(int j=2;j<4&&i+j<5;j++){
            for(int k=0;k<5;k++){
                for(int l=2;l<4&&k+l<5;l++){
                    double u=distance_ls_ls(p[a][i],p[a][i+j],p[b][k],p[b][k+l]);
                    if(ret>u)
                        ret=u;
                }
            }
        }
    }
    //cout<<ret<<endl;
    return ret;
}
 
 
 
int main(){
    while(cin>>n>>s>>g,n||s||g){
        p.clear();
        p.resize(n);
        for(int i=0;i<n;i++){
            double x,y,a,r;
            Point pot;
            cin>>x>>y>>a>>r;
            Point c=Point(x,y);
            for(int j=0;j<5;j++){
                //p[i].pb(c+polar(r,PI*(a+(double)j*72.0+90.0)/180.0));
            	p[i].pb(Point(x-sin((a+72*j)*PI/180)*r,y+cos((a+72*j)*PI/180)*r));
            }
        }
        //cout<<"      "<<distance_ls_p(p[0][4],p[0][1],p[2][2])<<endl;
 
         
        vector<vector<double> > cost(n,vector<double>(n,INF));
         
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
            	if(i==j){
            		cost[i][j]=0;
            		continue;
            	}
                double a=cal(i,j);
                cost[i][j]=a;
                cost[j][i]=a;
            }
        }
    	for(int k=0;k<n;k++){
    		for(int i=0;i<n;i++){
    			for(int j=0;j<n;j++){
    				cost[i][j]=min(cost[i][k]+cost[k][j],cost[i][j]);
    			}
    		}
    	}
    	//cout<<cost[s-1][g-1]<<endl;
    	printf("%.8lf\n",cost[s-1][g-1]);
        /*
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<cost[i][j]<<" ";
            }
            cout<<endl;
        }*/
         
        /*priority_queue<P,vector<P>,greater<P> > que;
        que.push(P(0,s-1));
        vector<double> d(n,INF);
        d[s-1]=0;
        while(!que.empty()){
            P q=que.top();
            int pos=q.second;
            double dist=q.first;
            que.pop();
            if(pos==g-1){
                printf("%.8lf\n",dist);
                break;
            }
            if(dist>d[pos]){
                continue;
            }
            for(int i=0;i<n;i++){
                 
                if(cost[pos][i]==INF){
                    continue;
                }
                if(cost[pos][i]+dist<d[i]){
                    que.push(P(cost[pos][i]+dist,i));
                    d[i]=cost[pos][i]+dist;
                }
                 
                 
            }
        }*/
         
    }
    return 0;
}