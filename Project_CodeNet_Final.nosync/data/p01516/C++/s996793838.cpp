                                        #include <bits/stdc++.h>
                                        #include<iostream>
                                        #include<cstdio>
                                        #include<vector>
                                        #include<queue>
                                        #include<map>
                                        #include<cstring>
                                        #include<string>
                                        #include <math.h>
                                        #include<algorithm>
                                    //    #include <boost/multiprecision/cpp_int.hpp>
                                        #include<functional>
                                #define int long long
                                        #define inf  1000000007
                                        #define pa pair<int,int>
                                        #define ll long long
                                        #define pal pair<double,pa>
                                        #define ppa pair<int,int>
                                        #define ppap pair<int,pa>
                                        #define ssa pair<string,int>
                                        #define  mp make_pair
                                        #define  pb push_back
                                        #define EPS (1e-12)
                                        #define equals(a,b) (fabs((a)-(b))<EPS)
                                  #define VI vector<int>
                                        using namespace std;
                                        
                                  class pas{
                                    	public:
                                    	int x,y;
                                    	pas(int x=0,int y=0):x(x),y(y) {}
                                    	pas operator + (pas p) {return pas(x+p.x,y+p.y);}
                                    	pas operator - (pas p) {return pas(x-p.x,y-p.y);}
                                    	pas operator * (int a) {return pas(x*a,y*a);}
                                    	pas operator / (int a) {return pas(x/a,y/a);}
                                    //	double absv() {return sqrt(norm());}
                                    	int norm() {return x*x+y*y;}
                                    	bool operator < (const pas &p) const{
                                   		return x != p.x ? x<p.x: y<p.y;
                                   	}
                                  //		bool operator < (const pas &p) const{
                                    //		return y != p.y ? y<p.y: x<p.x;
                                    //	}
                                    	bool operator == (const pas &p) const{
                                    		return x==p.x && y==p.y;
                                    	}
                                    };

                                        class Point{
                                        	public:
                                        	double x,y;
                                        	Point(double x=0,double y=0):x(x),y(y) {}
                                        	Point operator + (Point p) {return Point(x+p.x,y+p.y);}
                                        	Point operator - (Point p) {return Point(x-p.x,y-p.y);}
                                        	Point operator * (double a) {return Point(x*a,y*a);}
                                        	Point operator / (double a) {return Point(x/a,y/a);}
                                        	double absv() {return sqrt(norm());}
                                        	double norm() {return x*x+y*y;}
                                        	bool operator < (const Point &p) const{
                                        		return x != p.x ? x<p.x: y<p.y;
                                        	}
                                        	bool operator == (const Point &p) const{
                                        		return fabs(x-p.x)<EPS && fabs(y-p.y)<EPS;
                                        	}
                                        };
                                        typedef Point Vector;
                                 #define pl pair<int,pas>
                                        struct Segment{
                                        Point p1,p2;
                                        };
                                        
struct star{
Segment se[5];
};
                                         double dot(Vector a,Vector b){
                                        	return a.x*b.x+a.y*b.y;
                                        }
                                        double cross(Vector a,Vector b){
                                        	return a.x*b.y-a.y*b.x;
                                        }
                                    
            bool parareru(Point a,Point b,Point c,Point d){
            //	if(abs(cross(a-b,d-c))<EPS)cout<<"dd "<<cross(a-b,d-c)<<endl;
            	return abs(cross(a-b,d-c))<EPS;
            }
            double distance_ls_p(Point a, Point b, Point c) {
              if ( dot(b-a, c-a) < EPS ) return (c-a).absv();
              if ( dot(a-b, c-b) < EPS ) return (c-b).absv();
              return abs(cross(b-a, c-a)) / (b-a).absv();
            }
            bool is_intersected_ls(Segment a,Segment b) {
            	if(a.p1==b.p1||a.p2==b.p1||a.p1==b.p2||a.p2==b.p2) return false;
            	if(parareru((a.p2),(a.p1),(b.p1),(b.p2))&&parareru((a.p2),(a.p1),(b.p1),(b.p1))){
            //		cout<<"sss"<<endl;
            		if(dot(a.p1-b.p1,a.p1-b.p2)<EPS) return true;
            		if(dot(a.p2-b.p1,a.p2-b.p2)<EPS) return true;
            		if(dot(a.p1-b.p1,a.p2-b.p1)<EPS) return true;
            		if(dot(a.p1-b.p2,a.p2-b.p2)<EPS) return true;
            		return false;
            	}
              else return ( cross(a.p2-a.p1, b.p1-a.p1) * cross(a.p2-a.p1, b.p2-a.p1) < EPS ) && ( cross(b.p2-b.p1, a.p1-b.p1) * cross(b.p2-b.p1, a.p2-b.p1) < EPS );
            }
            double segment_len(Segment a){
            	
            	return (a.p1-a.p2).absv();
            }
            double segment_dis(Segment a,Segment b){
            	if(is_intersected_ls(a,b))return 0;
            	double r=distance_ls_p(a.p1, a.p2, b.p1);
            	r=min(r,distance_ls_p(a.p1, a.p2, b.p2));
            	r=min(r,distance_ls_p(b.p1, b.p2, a.p2));
            	r=min(r,distance_ls_p(b.p1, b.p2, a.p1));
            	return r;
            }
            Point intersection_ls(Segment a, Segment b) {
              Point ba = b.p2-b.p1;
              double d1 = abs(cross(ba, a.p1-b.p1));
              double d2 = abs(cross(ba, a.p2-b.p1));
              double t = d1 / (d1 + d2);
             
              return a.p1 + (a.p2-a.p1) * t;
            }
			pair<Point,Point> circle_intersection(Point c1,double r1,Point c2,double r2){
				double d=(c1-c2).absv();
				double h=(r1*r1-r2*r2+d*d)/2.0/d;
				double l=sqrt(r1*r1-h*h);
			//	cout<<d<<" "<<h<<" "<<l<<endl;
				Point asi=c1+(c2-c1)*h/((c2-c1).absv());
				Vector r1r2=(c2-c1)/((c2-c1).absv());
				Vector sui={r1r2.y,-r1r2.x};
			//	cout<<sui.x<<" "<<sui.y<<endl;
				pair<Point,Point> z=mp(asi+sui*l,asi-sui*l);
				if(z.first.x>z.second.x) swap(z.first,z.second);
				return z;
			}
double dist(star s1,star s2){
	double ans=10000000000.0;
	
	for(int i=0;i<5;i++)for(int j=0;j<5;j++){
		if( is_intersected_ls(s1.se[i],s2.se[j])) {
			
//			cout<<s1.se[i].p1.x<<" "<<s1.se[i].p1.y<<endl;
//			cout<<s1.se[i].p2.x<<" "<<s1.se[i].p2.y<<endl;
//			cout<<s2.se[j].p1.x<<" "<<s2.se[j].p1.y<<endl;
//			cout<<s2.se[j].p2.x<<" "<<s2.se[j].p2.y<<endl;
		return 0.0;
		}
		ans=min(ans,segment_dis(s1.se[i],s2.se[j]));
//		cout<<"   "<<i<<" "<<j<<" "<<segment_dis(s1.se[i],s2.se[j])<<endl;
	}
	return ans;
}
vector<star> ve;
double w[101][101];
     signed main(){
int n;
     	while(1){
     	cin>>n;
     		if(n==0) return 0;
     		
     		int s,t;
     		cin>>s>>t;
     		s--;
     		t--;
     		ve.clear();
     		for(int i=0;i<n;i++){
     			
     			star st;
     			double x,y,r,a;
     			cin>>x>>y>>r>>a;
     			double pi=3.1415926535;
     			r=r/180.0*pi;
     			
     			Point p[5];
     			for(int j=0;j<5;j++){
     				p[j].x=x-a*sin(r+pi*(j+0.0)/5.0*2.0);
     				p[j].y=y+a*cos(r+pi*(j+0.0)/5.0*2.0);
     				
     		//		cout<<p[j].x<<" "<<p[j].y<<endl;
     			
     			}
     			
     			st.se[0]={p[0],p[2]};
     			st.se[1]={p[1],p[3]};
     			st.se[2]={p[2],p[4]};
     			st.se[3]={p[3],p[0]};
     			st.se[4]={p[4],p[1]};
     			
     			ve.pb(st);
     			
     		}
     		
     		
     		for(int i=0;i<100;i++)for(int j=0;j<100;j++)w[i][j]=10000000.0;
     		for(int i=0;i<100;i++)w[i][i]=0.0;
     		
     		for(int i=0;i<n;i++)for(int j=i+1;j<n;j++){
     			double wer=dist(ve[i],ve[j]);
   //  			cout<<i<<" "<<j<<" "<<wer<<endl;
     			w[i][j]=wer;
     			w[j][i]=wer;
     		}
     		
     		for(int k=0;k<n;k++)for(int i=0;i<n;i++)for(int j=0;j<n;j++){
     			w[i][j]=min(w[i][j],w[i][k]+w[k][j]);
     		}
     		printf("%.10lf\n",w[s][t]);
     	
     	}

           	return 0;
           }
