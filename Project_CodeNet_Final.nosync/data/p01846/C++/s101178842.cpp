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
                                        #define ppap pair<pa,int>
                                  
                                        #define ssa pair<string,int>
                                        #define  mp make_pair
                                        #define  pb push_back
                                        #define EPS (1e-10)
                                        #define equals(a,b) (fabs((a)-(b))<EPS)
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
                                        using namespace std;
                               class pas{
                                        	public:
                                        	int x,y,h;
                                        	pas(int x=0,int y=0,int h=0):x(x),y(y),h(h) {}
                                        	bool operator < (const pas &p) const{
                                        		return x != p.x ? x<p.x: y<p.y;
                                        	}
                                        	bool operator == (const pas &p) const{
                                        		return abs(x-p.x)==0 && abs(y-p.y)==0;
                                        	}
                                        		
                                        
                                        };
                                        class pa2{
                                        	public:
                                        	int x,y;
                                        	pa2(int x=0,int y=0):x(x),y(y) {}
                                        	pa2 operator + (pa2 p) {return pa2(x+p.x,y+p.y);}
                                        	bool operator < (const pa2 &p) const{
                                        		return x != p.x ? x<p.x: y<p.y;
                                        	}
                                        	bool operator == (const pa2 &p) const{
                                        		return abs(x-p.x)==0 && abs(y-p.y)==0;
                                        	}
                                        		
                                        
                                        };
                                        
                                               #define ppa pair<int,pas>
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
            	if(parareru((a.p2),(a.p1),(a.p1),(b.p2))&&parareru((a.p2),(a.p1),(a.p1),(b.p1))){
            //		cout<<"sss"<<endl;
            		if(dot(a.p1-b.p1,a.p1-b.p2)<EPS) return true;
            		if(dot(a.p2-b.p1,a.p2-b.p2)<EPS) return true;
            		if(dot(a.p1-b.p1,a.p2-b.p1)<EPS) return true;
            		if(dot(a.p1-b.p2,a.p2-b.p2)<EPS) return true;
            		return false;
            	}
              else return ( cross(a.p2-a.p1, b.p1-a.p1) * cross(a.p2-a.p1, b.p2-a.p1) < EPS ) && ( cross(b.p2-b.p1, a.p1-b.p1) * cross(b.p2-b.p1, a.p2-b.p1) < EPS );
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
             
                            string itos( int i ) {
                            ostringstream s ;
                            s << i ;
                            return s.str() ;
                            }
                             
                            int gcd(int v,int b){
                            	if(v>b) return gcd(b,v);
                            	if(v==b) return b;
                            	if(b%v==0) return v;
                            	return gcd(v,b%v);
                            }
             
                            double distans(double x1,double y1,double x2,double y2){
                            	double rr=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
                            	return sqrt(rr);
                            	
                            }
                            
   //         int pr[2000010];
     //       int inv[2000010];
            /*
            int beki(int wa,int rr,int warukazu){
            	if(rr==0) return 1ll;
            	if(rr==1) return wa%warukazu;
            	if(rr%2==1) return (beki(wa,rr-1,warukazu)*wa)%warukazu;
            	int zx=beki(wa,rr/2,warukazu);
            	return (zx*zx)%warukazu;
            }
            
			int comb(int nn,int rr){
				int r=pr[nn]*inv[rr];
				r%=inf;
				r*=inv[nn-rr];
				r%=inf;
				return r;
			}
            
            void gya(int ert){
            	pr[0]=1;
            	for(int i=1;i<ert;i++){
            		pr[i]=(pr[i-1]*i)%inf;
            	}
            	for(int i=0;i<ert;i++) inv[i]=beki(pr[i],inf-2,inf);
            	
            }
             */
            
             //sort(ve.begin(),ve.end(),greater<int>());
                                     //----------------kokomade tenpure------------
            //vector<double> ans(100000000),ans2(100000000);
int a[20][20];
   signed main(){
string s;
   	while(1){
   	cin>>s;
   		if(s=="#")return 0;
   		
   		for(int i=0;i<10;i++)for(int j=0;j<10;j++)a[i][j]=0;
   		s+="/";
   		int h=1;
   		int d=1;
   		int w;
   		for(int i=0;i<s.length();i++){
   			if(s[i]=='/'){
   				h++;
   				w=d;
   				d=1;
   			}
   			if(s[i]>'0' && s[i]<='9') d+=s[i]-'0';
   			if(s[i]=='b'){
   				a[h][d]=1;
   				d++;
   			}
   		}
   		
   		int s1,s2,s3,s4;
   		cin>>s1>>s2>>s3>>s4;
   		a[s1][s2]=0;
   		a[s3][s4]=1;
   		
   		string ans="";
   		for(int i=1;i<=h-1;i++){
   			int d=0;
   			for(int j=1;j<=w-1;j++){
   				if(a[i][j]==1){
   					if(d>0){
   						ans+="0";
   						ans.back()+=d;
   					}
   					ans+="b";
   					d=0;
   				}
   				else d++;
   			}
   			if(d>0){
   			ans+="0";
   				ans.back()+=d;
   			}
   			if(i<h-1)	ans+="/";
   		}
   		cout<<ans<<endl;
   	}
   	return 0;
        }
